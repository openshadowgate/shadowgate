#include <std.h>

#pragma strict_types

inherit OBJECT;

//Mini curses and conditions that should vape with user.c:break_all_spells();

int clevel;
object target;

int iscurse = 1;

void create()
{
    ::create();
    set_name("curse_obj");
}

int is_curse()
{
    return iscurse;
}

void add_curse_to_victim(object victim)
{
   object *spells;

   if (!objectp(victim))
      return;

   if (!pointerp(victim->query_property("curses")) )
   {
      spells = ({});
   }
   else
   {
      spells = victim->query_property("curses");
   }
   spells+= ({TO});
   victim->remove_property("curses");
   victim->set_property("curses",spells);
}

int query_clevel()
{
    return clevel;
}

int set_clevel(int x)
{
    clevel = x;
}

int set_target(object x)
{
    target = x;
}

int set_iscurse(int x)
{
    iscurse = x;
}

varargs int apply_curse(object victim, int power)
{
    object tmp;
    tmp = new(file_name(TO));
    tmp->set_target(victim);
    tmp->set_clevel(power);
    tmp->add_curse_to_victim(victim);
    tmp->curse_effect();
    TO->remove();
}

void curse_effect()
{
    return;
}

void dest_effect()
{
    if(objectp(TO))
        TO->remove();
}
