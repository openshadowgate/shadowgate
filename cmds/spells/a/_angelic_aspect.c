#include <std.h>
#include <magic.h>
inherit SPELL;

string ashort;

void effect(int direction)
{
    if(direction>0)
    {
        caster->set_property("darkvision",1);
        caster->set_property("flying",1);
        caster->set_property("angelic_aspect",1);
    }
    else
    {
        caster->remove_property("flying");
        caster->remove_property("darkvision");
        caster->remove_property("angelic_aspect");

    }

    caster->add_ac_bonus(2*direction);
    caster->set_property("endurance",(clevel/10)*direction);
    caster->set_resistance("cold",10*direction);
    caster->set_resistance("acid",10*direction);

    return;
}

void create(){
    ::create();
    set_spell_name("angelic aspect");
    set_spell_level(([ "cleric": 5, "paladin": 3, "mage": 5 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS angelic aspect");
    set_damage_desc("levitating, AC2, darkvision, 10 DR to Acid and Cold");
    set_description("You take on an aspect of an angelic being, including some of its physical characteristics. This spell won't last outside of combat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if(caster->query_property("angelic_aspect"))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You're already infused with this aspect.%^RESET%^");
    }
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" raises above ground as "+caster->QS+" chants the spell.";
}

void spell_effect()
{

    ashort = "%^RESET%^%^ORANGE%^ (%^WHITE%^%^BOLD%^tr%^ORANGE%^a%^WHITE%^iled by fe%^RESET%^%^ORANGE%^a%^BOLD%^th%^RESET%^e%^ORANGE%^r%^BOLD%^%^WHITE%^ed w%^RESET%^i%^ORANGE%^n%^BOLD%^%^WHITE%^g%^ORANGE%^s%^BOLD%^%^ORANGE%^)";
    if(!(caster->query_alignment()%3))
        ashort = "%^RESET%^%^BOLD%^%^MAGENTA%^ (%^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^ra%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^le%^BOLD%^%^BLACK%^d by %^RESET%^%^MAGENTA%^bl%^BOLD%^%^BLACK%^ack %^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^in%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^MAGENTA%^)%^RESET%^";

    tell_room(ENV(caster),"%^BOLD%^%^WHITE%^As "+caster->QCN+" finishes the chant, feathery "+(!(caster->query_alignment()%3)?"%^BLACK%^black%^WHITE%^":"white")+" wings sprout from "+caster->QP+" shoulders!%^RESET%^");

    effect(1);
    caster->set_property("added short",({ashort}));
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_successful();
    call_out("test",ROUND_LENGTH*5);
}

void test()
{
    object * attackers;
    if(!objectp(caster))
        dest_effect();
    attackers = caster->query_attackers();
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You feel your mortality wavers...");
        call_out("test2",ROUND_LENGTH*10);
    }
    else
        call_out("test",ROUND_LENGTH*5);
}

void test2()
{
    object * attackers;
    if(!objectp(caster))
        dest_effect();
    attackers = caster->query_attackers();
    if(sizeof(attackers))
    {
        call_out("test",ROUND_LENGTH*5);
    }
    dest_effect();
    tell_object(caster,"%^BOLD%^%^WHITE%^You feel your mortality return as angelic aspect fades.");
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("added short",({ashort}));
        effect(-1);
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
