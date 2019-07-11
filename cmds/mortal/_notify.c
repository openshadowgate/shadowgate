/*
// The "notify" command.
// Written by Belphy@ShadowGate (9-27-94)
*/

#include <std.h>

inherit DAEMON;

int cmd_notify() {
   if (this_player()->query_logon_notify()) {
     this_player()->set_logon_notify(0);
     write("Notify login/logout messages turned OFF.");
   }
   else
   if (!this_player()->query_logon_notify()) {
     this_player()->set_logon_notify(1);
     write("Notify login/logout messages turned ON.");
   }
   this_player()->save_player();
   return 1;
}

void help()
{
  write("
%^CYAN%^NAME%^RESET%^

notify - toggle login notifications

%^CYAN%^DESCRIPTION%^RESET%^

This command toggles login notification. With notifications turned on, you'll see when people log in, but you won't see their names. 

Use this command with care if you have dropped PK flag.

%^CYAN%^SEE ALSO%^RESET%^

who, chfn, mail, brief, briefcombat, setenv, flag
");
}

