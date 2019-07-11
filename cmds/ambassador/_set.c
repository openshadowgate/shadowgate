//      /bin/ambassador/_set.c
//      from the Nightmare Mudlib
//      sets environment variables
//      from the TMI 0.8 distribution mudlib

#include <std.h>

inherit DAEMON;

int cmd_set(string arg) {
  int i;
  string * vars;
  string val, var;
  mixed mix;
  object act_ob;
  
  act_ob = previous_object();
  if (!arg)
    {
      vars = (string *)act_ob->regexp_query_env(".*");
      if (!vars || !sizeof(vars))
	{
	  notify_fail ("No environment variables set.\n");
	  return 0;
	}
      write ("Environment variables:\n");
      for (i = 0; i < sizeof (vars); i++) 
	{
	  printf("%-15s%s\n",vars[i],(string)act_ob->getenv(vars[i]));
	}
      return 1;
    }
  if (sscanf(arg,"%s %s",var,val) != 2)
    {
      val = "";
      var = arg;
    }
    if(var == "TITLE" && (string)act_ob->query_position() == "ambassador") {
      write("Ambassadors may not change their titles.\n");
      return 1;
    }
  act_ob->setenv(var,val);
  write ("Variable added: "+var+"\n");
  return 1;
}


void help ()
{
   write ("Usage: set [variable [value]]\n");
   write ("\nUsed by itself, set lists all environment variables which have been set.\n");
   write ("\nWith just a variable name as an argument, set will set the value of that\nenvironment variable to \"\".\n");
   write ("\nIf given a second argument, a value, a variable is created with that name and\nthat value if it doesn't exist.  If it already exists, the old value is\nreplaced with the new one.\n");
}
