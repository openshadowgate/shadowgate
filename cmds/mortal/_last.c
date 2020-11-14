// _last.c

// returns the last 10 lines sent from tell broadcast say and lines

#include <std.h>

inherit DAEMON;

int help();

int cmd_last(string str)
{
    int i, j;
    string* stuff, msg;


    if (str == "types") {
        tell_object(TP,"%^BOLD%^%^RED%^You're saving these channels: %^RESET%^" + implode(TP->query_message_classes(), ", "));
        return 1;
    }

    if (!str) {
        return help();
    }

    if (str == "tell") {
        str = "reply";
    }
    stuff = TP->query_messages(str);

    if (!stuff || !(j = sizeof(stuff))) {
        return notify_fail("There are no saved messages of that type.\n");
    }

    write("%^BOLD%^Last lines of " + str);
    for (i = 0; i < j; i++) {
        write("%^CYAN%^>> %^RESET%^" + stuff[i] + "%^RESET%^");
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

last - show last messages

%^CYAN%^SYNOPSIS%^RESET%^

last %^ORANGE%^%^ULINE%^CHANNEL%^RESET%^
last types

%^CYAN%^DESCRIPTION%^RESET%^

This command will print last messages of the type specified while you've been online. For example, %^ORANGE%^<last ooc>%^RESET%^ will display what had been said on ooc channel.

%^ORANGE%^<last types>%^RESET%^ will list all channel types you save massages of.

%^CYAN%^SEE ALSO%^RESET%^

say, channel use, lines, tell, emote
"
        );
}
