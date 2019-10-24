#include <std.h>

inherit DAEMON;

/*
  Based on rules in Lords of the wild
  Werewolf lycanthropy powers are in werewolf shapes
*/

int apply_template(object ob)
{
    ob->set("werewolf",1);
    return 1;
}

int remove_remplate(object ob)
{
    ob->delete("werewolf");
    return 1;
}
