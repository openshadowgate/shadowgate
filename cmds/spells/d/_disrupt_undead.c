// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("disrupt undead");
    set_spell_level(([ "mage" : 1 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS disrupt undead on TARGET");
    set_description("With this spell caster directs a ray of positive energy that severely harms undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect(int prof) {

    if((string)target->query_race() != "undead" && !target->query_property("undead"))
        tell_object(caster,"%^YELLOW%^As your target is not undead, the spell fizzles harmlessly.");
        
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^YELLOW%^You chant sonorously and direct a ray of light at "+target->QCN+"!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" chants sonorously and directs a ray of light at "+target->QCN+"!", ({caster}) );
    }
    define_base_damage(5);
    tell_object(place,"%^YELLOW%^A ray of light scorches "+target->QP+"!");
    damage_targ(target, target->query_target_limb(), sdamage,"positive energy");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

