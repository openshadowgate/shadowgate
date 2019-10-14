#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

string * JUDGEMENT_TYPES = ({
        "destruction",
            "healing",
            "justice",
            "piercing",
            "protection",
            "purity",
            "resiliency",
            "resistance",
//            "smiting"
});

string * active_judgements = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("DivineSpellcraft");
    feat_name("rally");
    feat_syntax("judgment FIRST [SECOND [THIRD]]");
    feat_prereq("Heh");
    feat_desc("");
//    set_required_for(({"second judgement","third judgement"}));
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    return 0;
    if(!objectp(ob)) return 0;
    if(!ob->is_class("inqusitor"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_judgment(string args)
{
    string first, second, third;
    if(!objectp(TP))
        return 0;
    if(!sizeof(TP->query_attackers()))
    {
        tell_object(TP,"You can't use judgement outside of combat.");
        return 1;
    }
    if(TP->query_property("active_judgements"))
    {
        string * judgements = TP->query_property("active_judgements");
        active_judgements(judgements,-1);
    }

    sscanf(args,"%s %s %s",first, second, third);
    clevel = TP->query_guild_level("inquisitor");
    if(first!="")
        if(member_array(first,JUDGEMENT_TYPES)!=-1)
        {
            active_judgements+=({first});
        }
        else
        {
            tell_object(TP,"You can't use judgement outside of combat.");
            return 1;
        }

    return 1;
}

void activate_judgements(string * judgements,int direction)
{
    string j;
    foreach(j in judgements)
    {
        if(member_array(j,JUDGEMENT_TYPES)!=-1)
            call_other(TO,"judgement_"+j,direction);
    }
}

void judgement_destruction(int direction)
{
    int bonus;
    bonus = clevel / 3 + 1;
    caster->add_damage_bonus(bonus*direction);
}

void judgement_healing(int direction)
{
    int bonus;
    bonus = clevel/18+1;
    caster->set_property("fast_healing",bonus*direction);
}

void judgement_justice(int direction)
{
    int bonus;
    bonus = clevel / 5 + 1;
    caster->add_attack_bonus(bonus*direction);
}

void judgement_piercing(int direction)
{
    caster->set_property("spell penetration",(clevel+10)*direction);
    caster->set_property("empowered",(clevel/12+1)*direction);
}

void judgement_protection(int direction)
{
    int bonus;
    bonus = clevel / 5 + 1;
    caster->add_ac_bonus(bonus*direction);
}

void judgement_purity(int direction)
{
    int bonus;
    bonus = clevel / 5 + 1;
    caster->add_saving_bonus("all",bonus);
}

void judgement_resiliency(int direction)
{
    int bonus;
    bonus = clevel / 5 + 1;
    caster->set_property("spell damage resistance",bonus*direction);
}

void check()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    call_out("check",ROUND_LENGTH);
}

void dest_effect()
{
    return;
}
