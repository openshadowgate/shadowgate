#include <std.h>


/*
  Based on rules in Lords of the wild
  Werewolf lycanthropy powers are in werewolf shapes
*/

string *races_allowed()
{
    return ({"human", "elf", "half-elf", "drow", "half-drow", "half-orc", "beastkin", "dwarf", "half-dwarf"});
}


int apply_template(object ob)
{
    ob->set("werewolf",1);
    return 1;
}

int remove_template(object ob)
{
    ob->delete("werewolf");
    return 1;
}
