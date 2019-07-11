#include <std.h>
#include <daemons.h>
#include <security.h>
#define TS "/daemon/treesave_d.c"

inherit DAEMON;

int help();
int cmd_assassinp(string str){
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
  
  if (!str) return help();
  if (sscanf(str,"%s %s %s", who, what, why) != 3) return help();
  ob = find_player(who);
  if (!ob) {
    if (!user_exists(who)) return notify_fail("The player "+who+" does not exist.\n");
    //load the player  
  } else {
    switch (what) {
    case "on":
    case "promote":
      ob->set("is_assassin",1);
      ob->add_search_path("/cmds/assassin");
      log_file("assassin", ob->query_name()+" gained assassin status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("assassin","\t\t "+why+"\n");

      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - recieved assassin status because: "+why);

      tell_object(TP,who+" is an assassin now.");
      break;
      // *************************************************************
    case "off":
    case "demote":
      ob->delete("is_assassin");
      ob->remove_search_path("/cmds/assassin");
      log_file("assassin", ob->query_name()+" lost assassin status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("assassin","\t\t "+why+"\n");
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - lost assassin status because: "+why);

      ob->update_channels();
      tell_object(TP,who+" is no longer an assassin.");
      break;
      // *************************************************************
    case "forbid":
    case "deny":
      log_file("assassin", ob->query_name()+" forbidden from assassin status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("assassin","\t\t "+why+"\n");

      ob->set("is_banned_assassin",1);
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - forbidden from assassin status because: "+why);
      tell_object(TP,who+" is forbidden from being an assassin now.");
      break;
      // ************************************************************
    case "permit":
    case "allow":
      log_file("assassin", ob->query_name()+" regained the ability to try for assassin status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("assassin","\t\t "+why+"\n");

      ob->delete("is_banned_assassin");
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - allowed to try becoming an assassin again because: "+why);
      tell_object(TP,who+" is not forbidden from being an assassin now.");

      break;
    default:
      help();
    }
    ob->update_channels();
  }
  return 1;
}

int help(){
  write("Syntax:  assassinp <who> <on/off/permit/forbid> <reason>\n");
  write("Allow is a synonym for permit, deny is a synonym for forbid.");
  write("Also: promote is a synonym for on, demote is a synonym for off.");

  return 1;
}
