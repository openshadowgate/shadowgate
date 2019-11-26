#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_shaken");
}

void status_effect()
{
    int i;
    if(target->query_property("effect_shaken"))
        return;

    target->set_property("effect_shaken",1);

    tell_object(target,"%^ORANGE%^You feel shaken.%^RESET%^");
    tell_room(ENV(target),"%^ORANGE%^"+target->QCN+" looks shaken.", target);

    power = target->query_level()/12+1;

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-power);
    target->add_attack_bonus(-power);
    target->add_saving_bonus("all",-power);

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^You no longer feel shaken.%^RESET%^");
        tell_room(ENV(target),"%^ORANGE%^"+target->QCN+" no longer looks shaken.", target);
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],power);
        target->add_attack_bonus(power);
        target->add_saving_bonus("all",power);
        target->remove_property("effect_shaken");
    }

    ::dest_effect();
}
