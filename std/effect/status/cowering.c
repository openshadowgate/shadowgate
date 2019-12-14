#include <std.h>
#include <magic.h>
#include <skills.h>
#include <daemons.h>

#pragma strict_types

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_cowering");
}

void status_effect()
{
    int i, x;
    object weapons;
    string exits;

    if(target->query_property("effect_cowering"))
        return;
    if(PLAYER_D->immunity_check(target,"fear"))
        return;

    target->set_property("effect_cowering",1);

    tell_object(target,"%^BLUE%^You are cowering in fear.%^RESET%^");

    power = target->query_level()/6+1;

    target->add_ac_bonus(-power);
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
        tell_object(target,"%^BLUE%^You are no longer cowering.%^RESET%^");
        target->add_ac_bonus(power);
        target->remove_property("effect_cowering");
    }

    ::dest_effect();
}
