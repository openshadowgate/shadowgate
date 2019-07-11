//Based on Cure light Wounds

#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("cure moderate wounds");
    set_spell_level(([ "cleric" : 2, "bard" : 2, "paladin" : 3, "ranger" : 3,"druid" : 3 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure moderate wounds on TARGET");
    set_description("Praying to their diety for a small miracle, the priest can attempt to heal a bit of damage to the "
"target.  As the caster's strength grows, she will find her prayer will heal more.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string query_cast_string() {
    string cast;

    if (interactive(CASTER)) {
        cast = "%^CYAN%^"+YOU+" starts to mumble a long worshipful "+
            "incantation!";
    } else {
         cast = "%^CYAN%^"+YOU+" starts to vibrate and a long "+
        "worshipful incantation to "+MINE+" deity sounds!";
    }
}

void spell_effect(int prof) {
 
    spell_successful();
    tell_room(place,"%^CYAN%^A moderate field radiates inward toward "+HIM+"!",({caster,target}));
    if (interactive(caster)) {
        if (target!=caster)
             tell_object(caster,"%^CYAN%^You restore"+
			" a moderate portion of life energy to "+target->QCN+"!");
    }
    tell_object(target,"%^CYAN%^A light aura pulses from "+caster->QCN+" toward your body"+
		" restoring moderate bit of strength.");

    damage_targ(target,target->return_target_limb(), -sdamage,"positive energy");
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
