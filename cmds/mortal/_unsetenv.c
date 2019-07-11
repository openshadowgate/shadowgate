//      /bin/ambassador/_unset.c
//      from the Nightmare Mudlib
//      used to unset environment variables
//      created by someone at TMI 0.8

#include <std.h>

inherit DAEMON;

int cmd_unsetenv(string arg) {
    string *vars;
    int i;
  string val, var;
  mixed mix;
  object act_ob;
  
  act_ob = previous_object();
  if (!arg) {
      notify_fail ("usage: unsetenv <variable_name>\n");
      return 0;
    }
  switch(arg) {
      case "SCREEN": case "LINES":
      case "TZONE":
      case "MOREPREFIX":
          break;
      case "TERM":
           return notify_fail("You don't want to unsetenv that!\n");
      default: return notify_fail("Invalid variable: "+arg+"\n");
    }
  if (!act_ob->getenv(arg)) {
      notify_fail("No such variable defined.\n");
      return 0;
    }
  act_ob->remove_env(arg);
    message("info",sprintf("Variable %s unset.", arg),this_player());
  return 1;
}

void help ()
{
   write ("Usage: unsetenv <variable name>\n");
   write ("\nThis command will remove an environment variable if it exists.\n");
   write ("See also: setenv\n");
}
