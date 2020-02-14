#include <std.h>

/*
  innate in /std/innate
  negative energy reversal in /std/magic/spell
  exhaustion in /std/living
  con stat in /std/living/body

  bonus damage in individual spells
*/

string *races_allowed()
{
    return ({"human", "elf", "half-elf", "half-orc", "half-ogre", "ogre", "yuan-ti", "drow", "half-drow", "minotaur", "saurian", "goblin", "gnoll", "bugbear", "orc", "firbolg", "halfling", "dwarf", "beastkin",});
}

int apply_template(object ob)
{
    ob->set_property("undead",1);
    ob->set("undead",1);
    return 1;
}

int remove_template(object ob)
{
    ob->delete("undead");
    ob->remove_property("undead");
    return 1;
}
