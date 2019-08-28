//spell_kill added by Circe 6/4/07 to stop bugs with this spell not starting combat
// Pator@ShadowGate
// Revised at jul 31 1996

#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("pator");
    set_spell_name("cause critical wounds");
    set_spell_level(([ "cleric" : 4, "paladin" : 4 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause critical wounds on TARGET");
    set_description("This spell siphons off life energy from the target. The effect of this spell is aimed at one limb of "
"the opponents body. During battle, this spell is very powerful and requires no special skills or abilities.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

string query_cast_string() {
   return "%^BOLD%^%^CYAN%^"+YOU+" starts to mumble a long worshipful incantation to "+MINE+" deity!";
}

void spell_effect(int prof) {
 
    if (!present(target, place)) {
        tell_object(caster, "%^CYAN%^"+target->QCN+" has escaped your grasp.");
        dest_effect();
        return;
    }

    spell_successful();
    tell_room(place,"%^BOLD%^%^CYAN%^A large field radiates outward from "+HIM+"!",({caster,target}));
   	tell_object(caster,"%^BOLD%^%^CYAN%^You siphon off a critical portion of energy"+
                " from "+target->QCN+"!");
    tell_object(target,"%^CYAN%^%^BOLD%^A large aura pulses outward from your body"+
                " siphoning off a critical bit of strength.");
 
	damage_targ(target,target->query_target_limb(),sdamage,"negative energy");
    spell_successful();
    spell_kill(target,caster);
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
