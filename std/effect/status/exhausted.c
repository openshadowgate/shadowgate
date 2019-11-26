#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

void create()
{
    ::create();
    set_name("effect_exhausted");
}

void status_effect()
{
    int i;
    if(target->query_property("effect_exhausted"))
        return;

    if(target->is_undead())
        return;

    target->set_property("effect_exhausted",1);

    tell_object(target,"%^RED%^You are exhausted.%^RESET%^");

    target->add_stat_bonus("strength", -4);
    target->add_stat_bonus("dexterity", -4);

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^RED%^You no longer are exhausted.%^RESET%^");
        target->add_stat_bonus("strength", -4);
        target->add_stat_bonus("dexterity", -4);
        target->remove_property("effect_exhausted");
    }

    ::dest_effect();
}
