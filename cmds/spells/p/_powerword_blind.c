#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int current;

void create() {
    ::create();
    set_spell_name("powerword blind");
    set_spell_level(([ "mage" : 7 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS powerword blind on TARGET");
    set_description("When the powerword stun blind is uttered, any creature of the caster's choice is blinded, reeling and unable to think coherently or to act for a duration dependent on the creature's current hit points.");
    set_verbal_comp();
    set_silent_casting(1);
    set_target_required(1);
    set_save("will");
}

void spell_effect(int prof) {
    int hpmin,hpmax, hpmax2, x;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You take in a deep breath and scream the words, 'SIGTHUS DISAPPEERUS!!!'");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" takes in a deep breath and screams the words, 'SIGTHUS DISAPPEERUS!!!'",({caster}));

    if(mind_immunity_check(target, "default"))
    {
        target->add_attacker(caster);
        damage_targ(target, target->return_target_limb(), roll_dice(7,8),"mental");
        spell_successful();
        dest_effect();
        return;
    }

    if(!do_save(target,-2))
    {
        tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" blinks rapidly then stares around blindly.%^RESET%^");
        target->set_temporary_blinded(roll_dice(2,4));
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^Nothing happens, they resisted blindness.");
        tell_object(target,"%^BOLD%^%^WHITE%^You shake it off, whatever that was.");
    }


   spell_successful();
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
