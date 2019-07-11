#include <std.h>

inherit DAEMON;

int cmd_unnickname (string arg) {
   mapping nicknames;
   object act_ob;
   
   act_ob = previous_object();
   if (!arg) {
      notify_fail ("usage: unnickname \\<nick_name>\n");
      return 0;
   }
   if (!act_ob->query_nickname(arg)) {
      notify_fail("No such nickname defined.\n");
      return 0;
   }
   act_ob->remove_nickname(arg);
   write ("Nickname removed: "+arg+"\n");
   return 1;
}

void help() {
    write("Syntax: <unnickname [string]>\n\n"
      "This command removes a nickname from your nickname list.\n"
    "Keep in mind that there is a trick to this command, since\n"
    "when entering your command, your command gets replaced with the nickname.\n"
      "So, to remove a nickname, escape by placing \\ before the nickname.\n"
    );
}
