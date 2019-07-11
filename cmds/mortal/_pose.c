/* added ability to pose a stance added to adjectives for RP purposes *Styx* 2/15/03
   added the ability to pose while bound for RP purposes ~Circe~ 10/3/03
*/
//added a check for invisibility before the pose tells the room -Tsera 11/1/04
#include <std.h>
#include <daemons.h>
#define CLASSES ({ "thief", "mage", "fighter", "cleric", "paladin", "antipaladin", "cavalier", "ranger", "bard", "assassin", "druid", "psion" })
#define MAXSTR 80


inherit DAEMON;

int cmd_pose(string str) {
    string myclass, oldclass,*tmp,*classes=({});
   int i;
/*   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
Taken out to allow posing while bound for RP ~Circe~ 10/3/03 
*/
   if (!str) {
      return notify_fail("You need to specify how you want to pose.\n");
   }
   if (sizeof(TP->query_attackers())) {
      return notify_fail("You're too busy right now.\n");
   }

   tmp = get_dir(DIR_CLASSES+"/");
   for(i=0;i<sizeof(tmp);i++)
   {
       classes += ({ replace_string(tmp[i],".c","") });
   }
   classes += CLASSES;

   if(member_array(str, classes) != -1) {
	myclass = str;
	if(!TP->is_class(myclass))
	    return notify_fail("You cannot pose as that myclass.\n");
	oldclass = TP->query_class();
	if(oldclass == myclass)
	    return notify_fail("You are already posing as a "+myclass+"!\n");
	TP->set_posed(myclass);
	TP->setenv("TITLE",(string)ADVANCE_D->get_new_title(TP));
  	tell_object(TP,"You are now posing as a "+myclass+"!");
	tell_object(TP,"If you meant to set a pose for your adjective, don't use a myclass name");
  	return 1;
   }
   if(str == "clear") {
    tell_object(TP,"Clearing pose.");//added to give the user some feedback when they clear the pose -Ares 1/3/06
	TP->remove_property("posed");
	return 1;
   }
   if(str == "show") {
// changed message for when there is no pose, which gave "...set as [0]" *Styx* 11/26/03
        if(!TP->query_property("posed")) {
	    write("You do not have a pose set.");
	    return 1;
        }
	write("Your pose is currently set as ["+TP->query_property("posed")+"].");
	return 1;
   }
   if(strlen(str) > MAXSTR)
	return notify_fail("Please be more brief, less than "+MAXSTR+" characters.  Note:  You don't have to add RESET at the end even if you use colors.\n");
   if(!TP->query_invis()){
   tell_room(ETP, "["+TPQCN+" poses "+str+"].", TP);
   }
   TP->remove_property("posed");
   TP->set_property("posed", str);
   write("Your pose is now set as ["+str+"].");
   log_file("pose", TPQCN+" set a pose of >>"+str+"<< on "+ctime(time())+" at "+base_name(ETP)+".\n");
   return 1;
}

int help() {
  write(
@HELP
   %^BOLD%^%^GREEN%^pose [classname]%^RESET%^
        Multiclassed characters sometimes need to pose as one of their classes, for instance to access a myclass-related help file.  If you specify a myclass, your status will be changed to posing as that myclass but it will not affect your description.

HELP
   );
   write(
@HELP
   %^BOLD%^%^GREEN%^pose [brief description of stance]%^RESET%^
        Please keep the description reasonable and reasonably brief.  This is meant to enable you to convey your relative position in a room or your current activity (i.e. sitting on the couch, at the bar, standing with sword drawn, at the desk writing, etc.) to those who enter a room or from a glance around by having it added to the end of your adjective.
        Yes, it is intentionally shown differently [sitting at the bar] than the actual states of (unconscious, bound) etc.

   %^BOLD%^%^GREEN%^pose clear%^RESET%^ will remove your current pose
Note:  Moving to another room will also remove a pose.

   %^BOLD%^%^GREEN%^pose show%^RESET%^ will show you your current pose
HELP
  );
}