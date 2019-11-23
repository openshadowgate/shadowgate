#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

void create()
{
    ::create();
    set_name("effect_panicked");
}

void status_effect()
{
    int i, x;
    object * weapons;
    string * exits, * ids;

    if(target->query_property("effect_panicked"))
        return;

    target->set_property("effect_panicked",1);

    tell_object(target,"%^BLUE%^You feel panicked.%^RESET%^");


    weapons = target->query_wielded();
    if(sizeof(weapons) && target->query_property("no disarm"))
    {
        tell_object(target,"%^CYAN%^You lose your grip on your weapons!%^RESET%^");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+" drops "+target->QP+" weapons!%^RESET%^",target);
    }
    for (x=0;x<sizeof(weapons);x++)
    {
        if(!objectp(weapons[x])) continue;
        ids = weapons[x]->query_id();
        if((int)weapons[x]->query_property("enchantment") < 0) continue;
        target->force_me("unwield "+ids[0]+"");
        target->remove_property("disarm time");
        target->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, 2)));
    }

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-2);
    target->add_attack_bonus(-2);
    target->add_damage_bonus(-2);
    target->add_saving_bonus("all",-2);

    exits = ENV(target)->query_exits();

    //If there are no exits you're covering
    if(!sizeof(exits))
    {
        "/std/effect/status/covering"->apply_effect(target,duration);
    }
    else
    {
        tell_object(target,"%^BOLD%^You flee before controlling yourself!%^RESET%^");
        tell_room(ENV(target),"%^BOLD%^"+target->QCN+" flees in fright!%^RESET%^",target);
        target->run_away();
    }

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You no longer feel panicked.%^RESET%^");
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],2);
        target->add_attack_bonus(2);
        target->add_damage_bonus(2);
        target->add_saving_bonus("all",2);
        target->remove_property("effect_panicked");
    }

    ::dest_effect();
}
