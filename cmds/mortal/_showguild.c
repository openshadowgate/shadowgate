#include <std.h>

inherit DAEMON;

int help();

void cmd_showguild(string str){
    string gld, tmp;

    if (!str) {
        tmp = "Your choices are: "+TP->query_guild_string();
        tell_object(TP, tmp);
        return 1;
    }
    
    if(sscanf(str, "%s %s", tmp, gld) != 2)
        return help();

    if(tmp != "on" && tmp != "off")
        return notify_fail("on or off??\n");

    if(!TP->in_guild(gld))
        return notify_fail("You are not in that guild.\n");

    if (tmp == "on") {
        TP->add_shguild(gld);
        write("You are now displaying your guild.");
        return 1;
    }

    if (tmp == "off") {
        TP->remove_shguild(gld);
        write("You are now hiding your guild.");
        return 1;
    }
}

int help(){
    write(
@OLI
showguild <on|off> <guildname>

Turns on or off whether others will see if you are in the
guild specified.  Guild must be exact, capitalization is
important.

'showguild' alone will tell you what guilds you are in.

OLI
);
    return 1;
}
