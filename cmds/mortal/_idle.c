///bin/user/_muds.c
//from the Nightmare mudlib
//     Display how long a player has been idle.
//     Written by Plura@Nightmare 930205
//     Changed to use visible() to take into account level 1 wizards by
//     Pallando@Nightmare 93-09-10
//     Changed to query_invis() to hide invisible wizards 04OCT93 by
//     Gregon@Nightmare
// added level check & restricting to immortals only *Styx* 8/16/03

#include <std.h>

inherit DAEMON;
void help();
static string parse_time(int i);

int cmd_idle(string str) {
   object ob;

   if(!str){
      help();
      return 1;
   }
// added level check & restricting to immortals only *Styx* 8/16/03
   if(!avatarp(TP)) {
      write("This command is currently restricted to immortals, sorry.");
      return 1;
   }
   if(TP->id(str)){
      write("You're obviously not idle.");
      return 1;
   }
   if(!ob = find_player(str)){
      write("Could not find '"+str+"'.");
      return 1;
   }
   if(!ob = find_player(lower_case(str))){
      write("Could not find '"+str+"'.");
      return 1;
   }
// added level check & restricting to immortals only *Styx* 8/16/03
   if(ob->query_invis() && ob->query_lowest_level() > TP->query_lowest_level()){
      write("Could not find '"+str+"'.");
      return 1;
   }
   if(!avatarp(TP) && avatarp(ob) && lower_case(str) == (string)ob->query_true_name()) {
      write("Could not find '"+str+"'.");
      return 1;
   }
//added this so wizzes can watch idle time of mortals even if invis. *Styx* 7/02
   if(interactive(ob) && avatarp(TP) && !wizardp(ob)) {
      write(capitalize(str)+" has been idle for " +parse_time(query_idle(ob)) +".");
      return 1;
   }
   if(interactive(ob) && !ob->query_invis() && !avatarp(TP)) {
      write(capitalize(str)+" has been idle for " +parse_time(query_idle(ob)) +".");
      return 1;
   }
   if(ob && !interactive(ob) && !ob->query_invis()) {
      write(capitalize(str) + " is link dead now.");
      return 1;}
   if(str) {
      write("Could not find '"+str+"'.");
      return 1;
   }
   help();
   return 1;
}

void help() {
   write("Syntax: idle <player>\n\n" +
         "Shows how long <player> has been idle.\n"
	 "Restricted to immortals only 8/2003 by Styx.\n\n"
         "See also: muds, finger, tell, reply\n"
        );
}

static string parse_time(int t) {
   string str;
   str=(t%60)+" s";
   t /= 60;
   if(t%60>0)
      str=t%60+" m "+str;
   t /= 60;
   if(t%24>0)
      str=t%24+" h "+str;
   t /= 24;
   if(t>0)
      str=t+" d "+str;
   return str;
}
