#include <std.h>

inherit DAEMON;

int cmd_unnickname(string arg)
{
    mapping nicknames;
    object act_ob;

    act_ob = previous_object();
    if (!arg) {
        notify_fail("usage: unnickname \\<nick_name>\n");
        return 0;
    }
    if (!act_ob->query_nickname(arg)) {
        notify_fail("No such nickname defined.\n");
        return 0;
    }
    act_ob->remove_nickname(arg);
    write("Nickname removed: " + arg + "\n");
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

unnickname - remove a nickname

%^CYAN%^SYNOPSIS%^RESET%^

unnickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will remove %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^ from list of used nick names.

Alternatively, type %^ORANGE%^<nickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^%^ORANGE%^>%^RESET%^ providing no more arguments.

%^CYAN%^SEE ALSO%^RESET%^

nickname, alias, unalias, history, last, colors
"
        );
}
