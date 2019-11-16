#include <std.h>

/*
  innate in /std/innate
  negative energy reversal in /std/magic/spell
  exhaustion in /std/living
  con stat in /std/living/body

  bonus damage in individual spells
*/

inherit DAEMON;

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
