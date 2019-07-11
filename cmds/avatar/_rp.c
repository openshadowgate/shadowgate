#include <std.h>
inherit DAEMON;

int cmd_rp(){
    object *usrs;
    object choice;

    usrs = users();
    choice = usrs[random(sizeof(usrs))];
    while(avatarp(choice)) choice = usrs[random(sizeof(usrs))];
    tell_object(TP, "And this random player is brought to you by Grendel's great random player fucker wither chooser.");
    tell_object(TP, "Survey says...  "+choice->query_name());
    return 1;
}

int help(){
    write("This command will tell you the name of 1 randomly chosen online player.");
    return 1;
}
