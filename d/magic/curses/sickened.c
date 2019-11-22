#include <std.h>
#include <magic.h>
#include <skills.h>

inherit CURSE;

void create()
{
    ::create();
    set_name("curse_sickened");

}

curse_effect()
{
    int i;
    tell_object(target,"%^BLUE%^You feel sickened.%^RESET%^");

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-2);
    target->add_attack_bonus(-2);
    target->add_damage_bonus(-2);
    target->add_saving_bonus("all",-2);

    call_out("dest_effect",ROUND_LENGTH*(clevel/12+1));
}

dest_effect()
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
    }

    ::dest_effect();
}
