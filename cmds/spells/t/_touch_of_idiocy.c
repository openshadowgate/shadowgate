#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int adjust,origstr, theProf;
// static means does change ????
static object orig_targ;

void create() {
    ::create();
    set_spell_name("touch of idiocy");
    set_spell_level(([ "mage" : 2 ]));
    set_spell_sphere("enchantment_charm");
    set_sorc_bloodlines(({"accursed"}));
    set_syntax("cast CLASS touch of idiocy on TARGET");
    set_description("With a touch, you reduce the target's mental faculties. Your successful melee touch attack applies a 1d6 penalty to the target’s Intelligence, Wisdom, and Charisma scores.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof)
{
    int roll;
    ::spell_effect();
    theProf = prof;
    set_orig_targ(target);

    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
    spell_kill(target,caster);
    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(target, "You are narrowly missed by a ray emanating from "+caster->QCN+".\n");
        tell_room(place, target->QCN+" is narrowly missed by a ray emanating from "+caster->QCN+".\n",({ caster, target}));
        tell_object(caster, "Your ray of enfeeblement missed "+target->QCN+".\n");
        spell_kill(target,caster);
        TO->remove();
    } else {
        spell_successful();
        target->set_property("idiocied", 1);
        tell_object(target, "%^BOLD%^%^MAGENTA%^You are hit by a ray emanating from "+caster->QCN+".");
        tell_object(target, "You suddenly feel very stupid.");
        tell_room(place, "%^BOLD%^%^BLUE%^"+target->QCN+" is hit by a ray emanating from "+caster->QCN+".\n", ({ caster, target}));
        tell_object(caster, "Your touch of idiocy hits "+target->QCN+"!\n");
        adjust=roll_dice(1,6);
        target->add_stat_bonus("intelligence", -adjust);
        target->add_stat_bonus("wisdom", -adjust);
        target->add_stat_bonus("charisma", -adjust);
        target->set_property("spelled", ({TO}) );
        call_out("dest_effect", (ROUND_LENGTH * clevel / 2));
    }
    return 1;
}

void dest_effect() {
    target=query_orig_targ();
    remove_call_out("dest_effect");
    if(objectp(target))
    {
        tell_object(target, "You recover your mental abilities.\n");
        target->remove_property("idiocied");
        target->remove_property_value("spelled", ({TO}) );
        target->add_stat_bonus("intelligence", adjust);
        target->add_stat_bonus("wisdom", adjust);
        target->add_stat_bonus("charisma", adjust);
        target->add_stat_bonus("wisdom", adjust);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
