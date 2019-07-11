#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("Duelist");
    feat_name("positioning");
    feat_prereq("Swipe");
    feat_syntax("positioning offensive|defensive|check");
    feat_desc("This feat will allow characters to slightly shift between defensive and offensive combat, increasing or decreasing their accuracy and resistance");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"swipe"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_positioning(string str)
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

    bonus = (int)caster->query_property("tactical_positioning");

    switch(arg)
    {

    case "defensive":
        if(bonus == 5)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your can't fight any more defensive!%^RESET%^");
            dest_effect();
            return;
        }
        caster->remove_property("tactical_positioning");
        caster->set_property("tactical_positioning",bonus + 1);
        caster->add_ac_bonus(1);
        caster->add_attack_bonus(-1);
        tell_object(caster,"%^BOLD%^%^RED%^You shift your stance to better defend against attacks!%^RESET%^");
        dest_effect();
        return;

    case "offensive":
        if(bonus == -5)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^Your can't fight any less defensive!%^RESET%^");
            dest_effect();
            return;
        }
        caster->remove_property("tactical_positioning");
        caster->set_property("tactical_positioning",bonus - 1);
        caster->add_ac_bonus(-1);
        caster->add_attack_bonus(1);
        tell_object(caster,"%^BOLD%^%^CYAN%^You shift your stance to fight more aggressively!%^RESET%^");
        dest_effect();
        return;

    case "check":

        tell_object(caster,"%^RESET%^%^GREEN%^You have shifted %^MAGENTA%^"+bonus+" %^RESET%^%^GREEN%^points into tactical positioning.%^RESET%^");
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

