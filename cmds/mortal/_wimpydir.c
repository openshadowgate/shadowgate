/*
// command: wimpydir
// Sets the direction in which one will flee in.
// Written by Buddha@TMI on 2/16/92
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use it.
   */

#include <std.h>

inherit DAEMON;

int help();

int cmd_wimpydir(string str) {
   if(!str) {
      write("Wimpydir set to: "+ (string)previous_object()->query_wimpydir() +
         ".\n");
      return 1;
   }
   if(!stringp(str)) {
      help();
      return 1;
   }
   previous_object()->set_wimpydir(str);
   write("Wimpydir now set to "+str+".\n");
   return 1;
}

int help() {
   write("Usage:\nwimpydir <direction>\n" +
      "This command will set the direction you will flee in when in combat.\n" +
      "If the direction isn't set or doesn't work, you will flee in a random\n" +
      "direction.\n" +
      "If no direction is specified, it will tell you the current setting.\n"
        "If retreat is specified it will return you to the previous room if possible.\n"+
      "See also: wimpy, kill\n"
   );
   return 1;
}

