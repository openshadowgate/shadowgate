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
            "smiting"
});

string * active_judgements = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("DivineSpellcraft");
    feat_name("rally");
    feat_syntax("judgement TYPE");
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

int cmd_judgement(string str)
{
    string first, second, third;
    if(!objectp(TP))
        return 0;
    return 1;
}

void execute_feat()
{
    clevel = TP->query_guild_level("inquisitor");
    return;
}

void judgement_destruction(int direction)
{
    int bonus;
    bonus = clevel / 3 + 1;
    caster->add_damage_bonus(bonus*direction);
}

void judgement_healing(int direction)
{
    if(direction>0)
        call_out("fast_healing",ROUND_LENGTH);
    else
        remove_call_out("fast_healing");
}
void fast_healing()
{
    caster->add_hp(1,clevel);
    call_out("fast_healing",ROUND_LENGTH);
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
