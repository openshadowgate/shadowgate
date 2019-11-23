#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

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

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-2);
    target->add_attack_bonus(-2);
    target->add_saving_bonus("all",-2);

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^You no longer feel shaken.%^RESET%^");
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],2);
        target->add_attack_bonus(2);
        target->add_saving_bonus("all",2);
        target->remove_property("effect_shaken");
    }

    ::dest_effect();
}
