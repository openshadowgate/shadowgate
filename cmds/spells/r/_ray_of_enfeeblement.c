#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int adjust,origstr, theProf;
// static means does change ????
static object orig_targ;

void set_orig_targ(object ot) { orig_targ = ot; }
object query_orig_targ() { return orig_targ; }

void create() {
    ::create();
    set_spell_name("ray of enfeeblement");
    set_spell_level(([ "mage" : 2 ]));
    set_spell_sphere("necromancy");
    set_sorc_bloodlines(({"ghoul"}));
    set_syntax("cast CLASS ray of enfeeblement on TARGET");
    set_description("A coruscating ray springs from your hand. You must succeed on a ranged touch attack to strike a target. The subject takes a penalty to Strength equal to 1d6+1 per two caster levels (maximum 1d6+5).");
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
        target->set_property("enfeebled", 1);
        tell_object(target, "%^BOLD%^%^MAGENTA%^You are hit by a ray emanating from "+caster->QCN+".\n");
        tell_object(target, "You suddenly feel very weak.\n");
        tell_room(place, "%^BOLD%^%^MAGENTA%^"+target->QCN+" is hit by a ray emanating from "+caster->QCN+".\n", ({ caster, target}));
        tell_object(caster, "Your ray of enfeeblement hits "+target->QCN+"!\n");
        origstr = target->query_base_stats("strength");
        adjust=roll_dice(1,6);
        adjust+=(clevel/2>5)?5:clevel/2;
        if(adjust < 0)  adjust = 0;
        if( (origstr - adjust) < 5)
            adjust = origstr - 5;       // don't let adjusted str go below 5
        target->add_stat_bonus("strength", -adjust);
        target->set_property("spelled", ({TO}) );
        spell_kill(target,caster);
        call_out("dest_effect", (ROUND_LENGTH * clevel / 2));
    }
    return 1;
}

void dest_effect() {
    target=query_orig_targ();
    remove_call_out("dest_effect");
    if(objectp(target))
    {
        tell_object(target, "You recover your strength.\n");
        target->remove_property("enfeebled");
        target->remove_property_value("spelled", ({TO}) );
        target->add_stat_bonus("strength", adjust);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
