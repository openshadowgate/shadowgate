
// --==** /cmds/priest/_heal.c **==--
// Modified by Pator@ShadowGate
// August 25 1995
#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("harm");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS harm on TARGET");
    set_description("%^RESET%^This spell will channel huge amount of negative energy into target and will allow the caster to cause massive amount damage.");
    set_save("will");
    set_target_required(1);
    set_helpful_spell(1);
}


string query_cast_string()
{
    string cast;
    if (interactive(caster))
    {
        cast = "%^BOLD%^%^BLACK%^"+caster->QCN+" folds "+caster->QP+" hands as "+caster->QS+" prays for a divine spell!\n";
    }
    else
    {
        cast = "%^BOLD%^%^BLACK%^"+caster->QCN+" calls for a divine spell!\n";
    }
    return "\n"+cast;
}


spell_effect(int prof)
{
    int rnd;
    if(!(target->is_undead()))
        set_helpful_spell(0);
    if (interactive(caster))
    {
        if ( caster == target )
        {
            tell_object(caster, "%^BOLD%^%^BLACK%^You reach out and channel fell energy at yourself.");
            tell_room(place, "%^BOLD%^%^BLACK%^"+YOU+" channels fell energy at "+caster->QO+"self.", ({ caster, target}) );
        }
        else
        {
            tell_object(caster, "%^BOLD%^%^BLACK%^You channel fell energy at "+target->QCN+".");
            tell_room(place, "%^BOLD%^%^BLACK%^"+YOU+" channels fell energy at "+target->QCN+".",({ caster}) );
        }
    }
    else
    {
        tell_room(environment(caster), "%^BOLD%^%^BLACK%^"+caster->QCN+" sends a beam of energy to "+target->QCN+".",({ caster, target }) );
        tell_object(target, "%^BOLD%^%^BLACK%^"+caster->QCN+" sends a beam of fell energy at you.");
    }

    rnd = - sdamage * 5/4;
    damage_targ(target,target->return_target_limb(),rnd,"negative energy");
    target->remove_paralyzed();
    target->set_poisoning((-1)*(int)target->query_poisoning());
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
