#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

void create()
{
    ::create();
    set_name("status_sickened");
}

int status_effect()
{
    int i;
    if(target->query_property("effect_sickened"))
        return;

    target->set_property("effect_sickened",1);

    tell_object(target,"%^BLUE%^You feel sickened.%^RESET%^");

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-2);
    target->add_attack_bonus(-2);
    target->add_damage_bonus(-2);
    target->add_saving_bonus("all",-2);

    call_out("dest_effect",ROUND_LENGTH*clevel);
    return 1;
}

int dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You no longer feel sickened.%^RESET%^");
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],2);
        target->add_attack_bonus(2);
        target->add_damage_bonus(2);
        target->add_saving_bonus("all",2);
        target->remove_property("effect_sickened");
    }
    ::dest_effect();
    return 1;
}
