//spell_kill added by Circe 6/4/07 to stop bugs with it not starting combat
#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("cause serious wounds");
    set_spell_level(([ "cleric" : 3, "paladin" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause serious wounds on TARGET");
    set_description("When cast it makes a serious wound on the target monster. It is almost as powerful in inflicting "
                    "wounds as the cure serious wounds is in healing them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

string query_cast_string() {
    return "%^CYAN%^"+YOU+" starts to mumble a complicated incantation to "+MINE+" deity!";
}

void spell_effect(int prof) {
    if (!present(target, place)) {
        tell_object(caster, "%^CYAN%^"+target->QCN+" has escaped your grasp.");
        dest_effect();
        return;
    }

    tell_room(place,"%^CYAN%^A solid field radiates outward from "+HIM+"!",({caster,target}));
   	tell_object(caster,"%^CYAN%^You siphon off a good portion of "+
                "energy from "+target->QCN+"!");
    tell_object(target,"%^CYAN%^A solid aura pulses outward from your "+
                "body siphoning off substantial bit of strength.");

    damage_targ(target,target->query_target_limb(),sdamage,"negative energy");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
