#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("hellball");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS hellball");
    set_description("The ultimate skill of the most trained evokers, this spell unleashes a hellish blast of energy in all directions from a single point directed by the caster. A simultaneous blast of sonic, acid, fire and electricity unleashes massive damage upon everyone near the caster!");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_damage_desc("quater of each acid, fire, electricity and sonic");
    set_save("reflex");
    set_components(([
      "mage" : ([ "citric acid" : 1, "magnets" : 1, "small drum" : 1, "sulfur" : 1, ]),
    ]));
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" forms a ball of raw %^RED%^e%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^n%^RESET%^%^CYAN%^t%^BOLD%^a%^RESET%^%^MAGENTA%^l%^WHITE%^%^BOLD%^ elemental energy above and detonates it.%^RESET%^";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;

    attackers = all_living(place);
    attackers = filter_array(attackers, "is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);

    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" detonates ball of %^RED%^e%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^n%^RESET%^%^CYAN%^t%^BOLD%^a%^RESET%^%^MAGENTA%^l%^WHITE%^%^BOLD%^ power, directing currents of raw energy at "+caster->QP+" enemies!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^The area is washed with bright colors but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) continue;
        admg=sdamage/4;
        if(do_save(target))
        {
            admg=admg/2;
        }
        tell_object(attackers[i],"%^BOLD%^%^WHITE%^Your flesh is scorched with %^GREEN%^acid%^WHITE%^, %^RED%^fire%^WHITE%^, %^CYAN%^sound%^WHITE%^ and %^ORANGE%^lightning%^WHITE%^!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"acid");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"fire");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"electricity");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"sonic");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
