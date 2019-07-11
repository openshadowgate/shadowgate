//      /bin/mortal/_setenv.c
//      from the Nightmare Mudlib
//      a limited set command for users
//      created by Descartes of Borg 930903

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_setenv(string str) {
    string cle, val;

    if(!str || sscanf(str, "%s %s", cle, val) != 2) 
      return notify_fail("Usage <setenv [variable] [value]>\n");
    switch(cle) {
      case "SCREEN": case "LINES":
        if(!atoi(val)) return notify_fail("Enter in a number.\n");
        else this_player()->setenv(cle, val);
        break;
      case "TZONE":
      case "MOREPREFIX":
        this_player()->setenv(cle, val);
        break;
      case "TERM":
        if(!TERMINAL_D->query_term_support(val)) {
          message("info", "Unknown terminal type.", this_player());
          val = "unknown";
        }
        this_player()->setenv("TERM", val);
        this_player()->reset_terminal();
        break;
      default: return notify_fail("Invalid variable: "+cle+"\n");
    }
    message("info",sprintf("Variable %s set to %s.", cle, val),this_player());
    return 1;
}

void help() { 
    message("help",
      "Syntax: <setenv [variable] [value]>\n\n"
      "Sets environment variables which customize the way the game "
      "appears to you.  You may set the following values:\n\n"
      "LINES: sets how many lines appear for paged information (like the "
      "who command) (default: 20)\n\nSCREEN: sets how wide your screen is so "
      "that information coming to you automatically gets wrapped to fit "
      "your screen width (default: 75)\n\nTERM: sets what set of instructions "
      "your terminal needs to be in colour (see help terminal) (default: "
      "unknown)\n\nTZONE: sets what time zone you are in for conversion "
      "of real world times into your time zone (default: PST)\n"
     "\nMOREPREFIX: Sets the prefix of the more command to be different, "
     "For instance if you need to change the color so you can read it or "
     "your terminal does not support white background on white very well."
     "\n",
      this_player()
    );
   write("See also: unsetenv");
}
