#include <std.h>

#pragma strict_types
#pragma strong_types
#pragma save_types

inherit OBJECT;

//Mini curses and status effects that should vape with user.c:break_all_spells();

/**
 * clevel and durations are synomims where it is appliable. Duration is taken in rounds.
 */
int clevel, duration;
object target;

void create()
{
    ::create();
    set_name("curse_obj");
}

void add_effect(object victim)
{
   object *spells;

   if (!objectp(victim))
      return;

   if (!pointerp(victim->query_property("status_effects")) )
   {
      spells = ({});
   }
   else
   {
      spells = victim->query_property("status_effects");
   }
   spells+= ({TO});
   victim->remove_property("status_effects");
   victim->set_property("status_effects",spells);
}

int query_clevel()
{
    return clevel;
}

int set_clevel(int x)
{
    duration = x;
    clevel = x;
}

int set_target(object x)
{
    target = x;
}

varargs int apply_effect(object victim, int power)
{
    object tmp;
    tmp = new(file_name(TO));
    tmp->set_target(victim);
    tmp->set_clevel(power);
    tmp->add_effect(victim);
    tmp->status_effect();
    TO->remove();
}

void status_effect()
{
    return;
}

void dest_effect()
{
    if(objectp(TO))
        TO->remove();
}
