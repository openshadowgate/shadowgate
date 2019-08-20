#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MeleeAccuracy");
    feat_name("expertise");
    feat_prereq("Intelligence 13");
    feat_syntax("expertise offensive|defensive|check");
    feat_desc("The Expertise feat will allow the character to shift  some of their focus from hitting a target to defending from it, making them  more difficult to hit with melee attacks.");
    set_target_required(0);
    set_required_for(({"disarm","knockdown","daze"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_base_stats("intelligence") < 13) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_expertise(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    if(str) str = lower_case(str);
    if(str != "offensive" && str != "defensive") { str = "check"; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int check_my_status(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_bound() || ob->query_unconscious() || ob->query_tripped())
    {
        tell_object(ob,"You are unable to move well enough to do that.");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    int bonus;

    if(!check_my_status(caster))
    {
        dest_effect();
        return;
    }

    ::execute_feat();

    bonus = (int)caster->query_property("combat_expertise");

    switch(arg)
    {

    case "defensive":
        if(bonus == 5)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your expertise can't make you fight any more defensive!%^RESET%^");
            dest_effect();
            return;
        }
        caster->remove_property("combat_expertise");
        caster->set_property("combat_expertise",bonus + 1);
        caster->add_ac_bonus(1);
        caster->add_attack_bonus(-1);
        tell_object(caster,"%^BOLD%^%^RED%^You shift your stance to better defend against attacks!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" shifts "+caster->QP+" stance to better "
            "defend against attacks!%^RESET%^",caster);
        dest_effect();
        return;

    case "offensive":
        if(bonus == 0)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your expertise can't make you fight any less defensive!%^RESET%^");
            dest_effect();
            return;
        }
        caster->remove_property("combat_expertise");
        caster->set_property("combat_expertise",bonus - 1);
        caster->add_ac_bonus(-1);
        caster->add_attack_bonus(1);
        tell_object(caster,"%^BOLD%^%^GREEN%^You shift your stance to fight more aggressively!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" shifts "+caster->QP+" stance to fight "
            "less defensively!%^RESET%^",caster);
        dest_effect();
        return;

    case "check":

        tell_object(caster,"%^RESET%^%^GREEN%^You have shifted %^MAGENTA%^"+bonus+" %^RESET%^%^GREEN%^points into "
            "expertise.%^RESET%^");
        dest_effect();
        return;
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
