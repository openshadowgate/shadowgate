//_taborfine.c - New command by Circe.  A way to keep track of 
//Tabor's laws, fines, and payments
#include <std.h>
#include <security.h>

#include <daemons.h>
inherit DAEMON;

void help() {
  
    write(
@CIRCE
This command is intended to help keep track of Tabor's fines.
The commands are:

   <taborfine view> - This will show the transactions and 
   fines in Tabor.

   <taborfine view latest> - This will show the last entries.

   <taborfine pay [player] [reason]> - Use this command to record 
   a fine you collected from a player so they are not charged 
   twice.

   <taborfine fine [player] [reason]> - This will record a fine 
   a player has been charged with in Tabor.  NOTE:  To please 
   include the fine amount in your reason!  
       
   I'm looking at making a <search> command for this, but with it
   being in such a basic state, for now we'll just have to slush 
   through and hopefully keep the file small.
CIRCE
    );
}

int cmd_taborfine(string str) {
	object ob;
	string opt, who, reason;
	if(!str) {
        help();
        return 1;
    }
    if(str == "view") {
       tell_player(TP,"These are the fines "+
          "and charges in Tabor:\n");
       if(!file_exists("/log/tabor_law")){
          tell_object(TP,"There are no cases recorded!");
          return 1;
       }
       TP->more("/log/tabor_law");
       return 1;
    }
    if(str == "view latest") {
       tell_player(TP,"These are the most recent fines "+
          "and charges in Tabor:\n");
       if(!file_exists("/log/tabor_law")){
          tell_object(TP,"There are no cases recorded!");
          return 1;
       }
       TP->tail("/log/tabor_law");
       return 1;
    }
    if(sscanf(str, "%s %s %s",opt,who,reason) != 3) {
          help();
          return 1;
    }
    if(!(ob = user_exists(who = lower_case(who))))
	return notify_fail("That player does not seem to exist or you "+
         "have the command in the wrong order.\n");
    if(opt == "pay") {
       log_file("tabor_law",""+TPQN+" recorded a paid fine for "+who+" because "+
          ""+reason+" "+ctime(time())+"\n");
       tell_object(TP,"Payment recorded for "+who+".  Thank you.");
       return 1;
    }
    if(opt == "fine") {
       log_file("tabor_law",""+TPQN+" charged "+who+" a fine of "+
          ""+reason+" "+ctime(time())+"\n");
       tell_object(TP,"Fine recorded for "+who+" for "+reason+".  Thank you.");
       return 1;
    }
    help();
    return 1;
}


