#include <std.h>
#include <daemons.h>
#include <security.h>
#include "/d/common/common.h"
#define TS "/daemon/treesave_d.c"

inherit DAEMON;

int help();
int cmd_ambassadorp(string str){
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

  if (!str) return notify_fail("Usage: ambassadorp <who> <on/off> <reason>\n");
  if (sscanf(str,"%s %s %s", who, what, why) != 3) return notify_fail("Usage: ambassadorp <who> <on/off> <reason>\n");
  ob = find_player(who);
  if (!ob) {
    if (!user_exists(who)) return notify_fail("The player "+who+" does not exist.\n");
    //load the player  
  } else {
    switch (what) {
    case "on":
//      seteuid(UID_ADVANCE);
//      ob->set_position("high mortal"); 
      seteuid(getuid());
//      ob->add_search_path("/cmds/hm");
//      message("info","All hail "+capitalize(ob->query_name())+" the new high mortal!\n",users());
      log_file("ambassador", ob->query_name()+" gained ambassador status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("ambassador","\t\t "+why+"\n");
 
        SAVE_D->set_value("n_ambassador",who);
 
        new(N_AMB_RING)->move(ob);
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - recieved ambassador status because: "+why);
//      ob->set_max_mp(2*((int) ob->query_stats("intelligence") + (int)ob->query_stats("wisdom")));
      tell_object(TP,who+" is a ambassador now.");
      break;
    case "off":
    case "demote":

////      seteuid(UID_ADVANCE);
 
     SAVE_D->remove_name_from_array("n_ambassador",who);
//      ob->set_position("player");
//      seteuid(getuid());
//      ob->remove_search_path("/cmds/hm");
//      message("info",capitalize(ob->query_name())+" has lost "+ob->query_possessive()+" hm status.",users());
      seteuid(UID_LOG);
      log_file("ambassador", ob->query_name()+" lost ambassador status "+ctime(time())+" by: "+TP->query_name()+".\n");
      log_file("ambassador","\t\t "+why+"\n");
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - lost ambassador status because: "+why);
//      ob->disable_high_mostal(ob);
//      ob->update_channels();
      tell_object(TP,who+" is no longer a high mortal.");
      break;
    default:
      help();
      break;
    }
    ob->update_channels();
  }
  return 1;
}

int help(){
  write("Syntax:  ambassadorp <who> <on/off> <reason>\n");
  return 1;
}
