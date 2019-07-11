#include <clock.h>
#include <spell.h>
inherit SPELL;

int abonus; 
int duration;

void create() {
    ::create();
    set_spell_name("lesser transformation");
    set_spell_level(([ "psion" : 7 ])); 
    set_spell_sphere("alteration");
    set_discipline("egoist");
    set_syntax("cast CLASS lesser transformation");
    set_description("A lesser form of transformation will reshape casters in a minor way, empowering their muscles and granting better prowess in the combat. Much less powerful than its greater version it won't impede casters ability to use offensive spells. This spell will be overwritten by similar effects, such as rage and transformation.

This spell grants (1 + (caster level) / 16) bonus attacks to caster and the same amount to athletics skill and reflex saving bonus.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell() {
    if(caster->query_property("lesser_transformation") || caster->query_property("raged") || caster->query_property("transformed"))
    {
      tell_object(caster,"You're already under a similar effect!");
      return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    abonus = 1 + (clevel / 16);
    duration = 1800 + (clevel * 10);


    tell_object(caster,"%^MAGENTA%^You feel agitated as your muscles tense.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" seems agitated and restless as "+caster->QP+" muscles become tensed.%^RESET%^",caster);
    
    caster->set_property("fighter_attacks_mod",abonus);
    caster->add_skill_bonus("athletics",abonus);
    caster->add_saving_bonus("reflex",abonus);
    caster->set_property("lesser_transformation",1);
    caster->set_property("spelled", ({TO}) );    
    spell_successful();
    addSpellToCaster();
    //TODO: add test that checks for rage/transformation and calls dest_effect
    call_out("dest_effect",(clevel*20));
}

void dest_effect()
{
    if(objectp(caster)) 
    {
        caster->remove_property("lesser_transformation");
        caster->set_property("fighter_attacks_mod",-abonus);
        caster->add_skill_bonus("athletics",-abonus);
        caster->add_saving_bonus("reflex",-abonus);
        tell_object(caster,"%^MAGENTA%^You feel calm and lethargic as your muscles return to normal state.");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" appears calm and lethargic as transformation fades away.%^RESET%^",caster);

    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

