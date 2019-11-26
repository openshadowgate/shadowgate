#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("status_sickened");
}

int status_effect()
{
    int i;

    tell_object(target,"%^BLUE%^You feel sickened.%^RESET%^");
    tell_room(ENV(target),"%^BLUE%^"+target->QCN+" looks sickened.", target);

    power=target->query_level()/12+1;

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-power);
    target->add_attack_bonus(-power);
    target->add_damage_bonus(-power);
    target->add_saving_bonus("all",-power);

    call_out("dest_effect",ROUND_LENGTH*clevel);
    return 1;
}

int dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You no longer feel sickened.%^RESET%^");
        tell_room(ENV(target),"%^BLUE%^"+target->QCN+" no longer looks sickened.", target);
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],power);
        target->add_attack_bonus(power);
        target->add_damage_bonus(power);
        target->add_saving_bonus("all",power);
    }
    ::dest_effect();
    return 1;
}
