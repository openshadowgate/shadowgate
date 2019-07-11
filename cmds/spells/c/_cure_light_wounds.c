#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("pator");
    set_spell_name("cure light wounds");
    set_spell_level(([ "cleric" : 1, "bard" : 1, "paladin" : 1, "ranger" : 2, "druid" : 1 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure light wounds on TARGET");
    set_description("This spell heals wounds on a limb of the target.  It is a nice spell to quickly heal little damages "
"but don't expect too much out of it.  The spell will grow with the caster as he gains in power.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string query_cast_string() {
    string cast;

    if (interactive(CASTER)) {
      cast = "%^CYAN%^"+YOU+" starts to mumble a long worshipful"+
		" incantation!";
    } else {
         	cast = "%^CYAN%^"+YOU+" starts to vibrate and a long "+
			"worshipful incantation to "+MINE+" deity sounds!";
    }
}

void spell_effect(int prof) {
    tell_room(place,"%^CYAN%^A faint field radiates inward toward "+HIM+"!",({caster,target}));
    if (interactive(caster)) {
        if (target!=caster)
             tell_object(caster,"%^CYAN%^You restore a small portion of energy to "+HIM+"!");
    }
    tell_object(target,"%^CYAN%^A faint aura pulses from "+caster->QCN+" and into your body,"+
		" restoring a small bit of strength.");

    damage_targ(target,target->return_target_limb(), -sdamage,"positive energy");
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
