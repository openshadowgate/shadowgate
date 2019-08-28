//spell_kill added by Circe 6/4/07 to stop bugs with this spell not starting combat
#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("cause moderate wounds");
    set_spell_level(([ "cleric" : 2,"paladin":2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause moderate wounds on TARGET");
    set_description("When cast, this prayer will draw some energy from the target, inflicting him with a wound.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

string query_cast_string() {
   return "%^BOLD%^%^CYAN%^"+YOU+" starts to mumble a small incantation to "+MINE+" deity!";
}

void spell_effect(int prof) {
    spell_successful();
    if (!present(target, place)) {
        tell_object(caster, "%^CYAN%^"+target->QCN+" has escaped your grasp.");
        dest_effect();
        return;
    }

    tell_room(place,"%^BOLD%^%^CYAN%^A moderate field radiates outward"+
              " from "+HIM+"!",({caster,target}));
    tell_object(caster,"%^CYAN%^%^BOLD%^You siphon off a moderate bit"+
                " of energy from your "+target->QCN+"!");
    tell_object(target,"%^CYAN%^%^BOLD%^A steady aura pulses outward from "+
                "your body and takes a moderate bit of your strength.");

	damage_targ(target,target->query_target_limb(),sdamage,"negative energy");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}
void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
