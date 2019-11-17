#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

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
object caster;
int clevel;

void create()
{
    ::create();
    set_name("judgement_obj");
    set("id", ({ "judgement_obj" }) );
    set("short", "");
    set("long", "");
    set_weight(0);
}

void setup_judgement(object mycaster, int myclevel)
{
    caster = mycaster;
    clevel = myclevel;
}

void activate_judgements(string * judgements)
{
    if(sizeof(active_judgements))
    {
        apply_judgements(active_judgements,-1);
    }
    active_judgements = judgements;
    apply_judgements(judgements,1);
    tell_object(caster,"%^BOLD%^%^WHITE%^You with a mere will you call out to the arcane for the strength.");
    call_out("check",ROUND_LENGTH);
}

string * query_judgement_types()
{
    return JUDGEMENT_TYPES;
}

void apply_judgements(string * judgements,int direction)
{
    string j;
    int power;
    foreach(j in judgements)
    {
        if(member_array(j,JUDGEMENT_TYPES)!=-1)
        {
            power = clevel;
            if(FEATS_D->usable_feat(caster,"slayer"))
                if(caster->query("slayer_judgement")==j)
                    power+=5;
            call_other(TO,"judgement_"+j,direction,power);
        }
    }
}

void judgement_destruction(int direction, int power)
{
    int bonus;
    bonus = power / 3 + 1;
    caster->add_damage_bonus(bonus*direction);
}

void judgement_healing(int direction, int power)
{
    int bonus;
    bonus = power/18+1;
    caster->set_property("fast healing",bonus*direction);
}

void judgement_justice(int direction, int power)
{
    int bonus;
    bonus = power / 5 + 1;
    caster->add_attack_bonus(bonus*direction);
}

void judgement_piercing(int direction, int power)
{
    caster->set_property("spell penetration",(power+10)*direction);
    caster->set_property("empowered",(power/12+1)*direction);
}

void judgement_protection(int direction, int power)
{
    int bonus;
    bonus = power / 5 + 1;
    caster->add_ac_bonus(bonus*direction);
}

void judgement_purity(int direction, int power)
{
    int bonus;
    bonus = power / 5 + 1;
    caster->add_saving_bonus("all",bonus);
}

void judgement_resiliency(int direction, int power)
{
    int bonus;
    bonus = power + 1;
    caster->set_property("spell damage resistance",bonus*direction);
}

void check()
{
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }
    if(!sizeof(caster->query_attackers()))
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^As the battle comes to an end your arcane zeal recedes.%^RESET%^");
        apply_judgements(active_judgements,-1);
        TO->remove();
        return;
    }
    call_out("check",ROUND_LENGTH);
}
