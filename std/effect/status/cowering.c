#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

void create()
{
    ::create();
    set_name("effect_covering");
}

void status_effect()
{
    int i, x;
    object weapons;
    string exits;

    if(target->query_property("effect_covering"))
        return;

    target->set_property("effect_covering",1);

    tell_object(target,"%^BLUE%^You are covering in fear.%^RESET%^");

    target->add_ac_bonus(-2);
    tell_object(target,"%^BOLD%^%^BLUE%^Unable to contain your terror, you cower!%^RESET%^");
    tell_room(ENV(target),"%^BOLD%^%^BLUE%^"+target->QCN+" cowers in terror!%^RESET%^",target);
    target->set_paralyzed(duration*8,"%^BLUE%^You cannot contain your fear to do that!");

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You are no longer covering.%^RESET%^");
        target->add_ac_bonus(2);
        target->remove_property("effect_covering");
    }

    ::dest_effect();
}
