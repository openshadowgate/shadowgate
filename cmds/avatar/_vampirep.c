#include <std.h>
#include <daemons.h>
#include <security.h>
#define TS "/daemon/treesave_d.c"
inherit DAEMON;
int help();
int cmd_vampirep(string str){
  string who;
  string why;
  string what;
  object ob;
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
  
  if (!str) return notify_fail("Usage: vampirep <who> <on/off> <reason>\n");
  if (sscanf(str,"%s %s %s", who, what, why) != 3) return notify_fail("Usage: vampirep <who> <on/off>
<reason>\n");
  ob = find_player(who);
  if (!ob) {
    if (!user_exists(who)) return notify_fail("The player "+who+" does not exist.\n");
    //load the player  
  } else {
    switch (what) {
    case "on":
    case "enable":
      log_file("vampire", ob->query_name()+" gained vampire status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("vampire","\t\t "+why+"\n");
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " +ctime(time()) + " - recieved vampire status because: "+why);
      tell_object(TP,who+" is a vampire now.");
      who->set("vampire",1);
      who->set("undead",1);
      tell_object(who,"Thou art a vampire now.");
      break;
    case "off":
    case "demote":
      // message("info",capitalize(ob->query_name())+" has lost "+ob->query_possessive()+" vampire status.",users());
      seteuid(UID_LOG);
      log_file("vampire", ob->query_name()+" lost vampire status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("vampire","\t\t "+why+"\n");
      seteuid(getuid());
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " +
ctime(time()) + " - lost vampire status because: "+why);
      tell_object(TP,who+" is no longer a vampire.");
      who->set("undead",0);
      who->set("vampire",0);
      tell_object(who,"Thou art no longer a vampire.");
      break;
    default:
      help();
      break;
    }
  }
  return 1;
}
int help(){
  write("Syntax:  vampirep <who> <on/off> <reason>\n");
  return 1;
}
