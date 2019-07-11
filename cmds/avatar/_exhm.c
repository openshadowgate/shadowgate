#include <std.h>
#include <daemons.h>
#include <security.h>
#define TS "/daemon/treesave_d.c"
#define CMD_NOTE "/cmds/avatar/_note.c"
inherit DAEMON;

int cmd_exhm(string str){
  string who, why, what;
  int mycap;
  object ob;

  string posxxx; 
  if(!objectp(TP)) return 0;
  posxxx = lower_case((string)TP->query_position());
  if(posxxx == "builder" || posxxx == "apprentice") {
    tell_object(TP,"You cannot use this command as a builder or apprentice.");
    return 1;
  }
  
  if (!str) return notify_fail("Usage: exhm <who> <on/off> <reason>\n");
  if(sscanf(str,"%s %s %s", who, what, why) != 3) return notify_fail("Usage: exhm <who> <on/off> <reason>\n");
  ob = find_player(who);
  if(!ob) return notify_fail("The player "+who+" does not exist.\n");
  if(avatarp(ob)) return notify_fail("No way in heck is that right!\n");
  if(high_mortalp(ob)) return notify_fail("I think you're using the wrong command, boss.\n");
  if(what == "on"){
    if(ob->query("ex_hm")) return notify_fail("That player already has been marked as being a HM.\n");
    seteuid(UID_ADVANCE);
    ob->set("ex_hm",1);
//    ob->set("no advance",0);
    seteuid(getuid());
    log_file("high_mortal", ob->query_name()+" was marked as a previous HM: "+ctime(time())+" by: "+TP->query_name()+".\n");
    log_file("high_mortal","\t\t "+why+"\n");
    TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - previous HM status added because: " + why + ".");
//    CMD_NOTE->format_checkpoint(who,"%^ORANGE%^Level capped at 0.%^RESET%^");
    tell_object(TP,who+" is an ex-hm now.");
    return 1;
  }
  if(what == "off"){
    if(!ob->query("ex_hm")) return notify_fail("That player does not have been marked as being a HM to remove.\n");
    seteuid(UID_ADVANCE);
    ob->delete("ex_hm");
//    if(ob->is_singleClass()) mycap = 33;
//    else mycap = 30;
//    ob->set("no advance",mycap);
    seteuid(getuid());
    log_file("high_mortal", ob->query_name()+" lost ex-HM status: "+ctime(time())+" by: "+TP->query_name()+".\n");
    log_file("high_mortal","\t\t "+why+"\n");  
    TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - ex-HM status lost because: " + why + ".");
//    CMD_NOTE->format_checkpoint(who,"%^ORANGE%^Level capped at "+mycap+".%^RESET%^");
    tell_object(TP,who+" is no longer an ex-HM.");
    return 1;
  }
  return notify_fail("Usage: exhm <who> <on/off> <reason>\n");
}

int help(){
  write("Syntax:  exhm <who> <on/off> <reason>\n"
"Allows you to award or revoke ex-HM status.\n");
  return 1;
}
