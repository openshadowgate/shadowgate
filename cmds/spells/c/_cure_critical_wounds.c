// Revised by Pator@ShadowGate
// Aug 8 1996

#include <priest.h>

inherit SPELL;

create() {
    ::create();
    set_author("pator");
    set_spell_name("cure critical wounds");
    set_spell_level(([ "cleric" : 4, "bard" : 4,"druid" : 5, "paladin" : 4, "paladin" : 4, "ranger" : 4 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure critical wounds on TARGET");
    set_description("This pray will heal large amounts of damage and wounds to the target.  As the caster's power grows, "
"he will find he is able to heal more damage.");
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
         cast = "%^CYAN%^"+YOU+" starts to vibrate and a long worshipful"+
		" incantation to "+MINE+" deity sounds!";
    }
}

void spell_effect(int prof) {

    tell_room(place,"%^CYAN%^A solid field radiates inward toward "+HIM+"!",({caster,target}));
    if (interactive(caster)) {
        if (target!=caster)
            tell_object(caster,"%^CYAN%^You restore a large portion"+
                        " of life force energy to "+HIM+"!");
    }
    tell_object(target,"%^CYAN%^A solid field radiates from "+caster->QCN+", restoring a"+
                " large bit of your strength.");

    damage_targ(target,target->return_target_limb(), -sdamage*5/4,"positive energy");
    if((target->query_race() == "undead" ||
        target->query_property("undead")))
        spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
