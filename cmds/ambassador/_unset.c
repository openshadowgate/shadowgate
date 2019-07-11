//      /bin/ambassador/_unset.c
//      from the Nightmare Mudlib
//      used to unset environment variables
//      created by someone at TMI 0.8

#include <std.h>

inherit DAEMON;

int cmd_unset(string arg) {
    string *vars;
    int i;
  string val, var;
  mixed mix;
  object act_ob;
  
  act_ob = previous_object();
  if (!arg) {
      notify_fail ("usage: unset <variable_name>\n");
      return 0;
    }
  if (!act_ob->getenv(arg)) {
      notify_fail("No such variable defined.\n");
      return 0;
    }
  act_ob->remove_env(arg);
  write ("Variable removed: "+arg+"\n");
  return 1;
}

void help ()
{
   write ("Usage: unset <variable name>\n");
   write ("\nThis command will remove an environment variable if it exists.\n");
   write ("See also: set\n");
}
