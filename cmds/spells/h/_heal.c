
// --==** /cmds/priest/_heal.c **==--
// Modified by Pator@ShadowGate
// August 25 1995
#include <priest.h>

inherit SPELL;

void create() 
{
    ::create();
    set_spell_name("heal");
    set_spell_level(([ "cleric" : 6, "druid" : 7 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS heal on TARGET");
    set_description("%^RESET%^This spell will channel huge amount of positive energy into target and will allow the caster to cure massive amount damage from wounds and diseases.

See also: heal *player commands");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_casting_time(15);
    set_helpful_spell(1);
}


string query_cast_string() 
{
    string cast;
    if (interactive(caster))
    {
        cast = caster->QCN+" folds "+caster->QP+
            " hands as "+caster->QS+" prays for a divine spell!\n";
    }
    else
    {
        cast = caster->QCN+" calls for a divine spell!\n";
    }
    return "\n"+cast;
}


spell_effect(int prof) 
{
    int rnd;
    if (interactive(caster)) 
    {
        // CAST UPON ONESELF
        if ( caster == target ) 
        { 
            tell_object(caster, "You reach out and touch the tip of your nose and you heal yourself completely.");
            tell_room(place, YOU+" reaches out and touches the tip of "+caster->QP+" nose and heals "+caster->QO+"self.", ({ caster, target}) );
        } 
        else 
        {
            // caster =\= target
            tell_object(caster, "You reach out and touch the tip of "+target->QCN+"'s nose and you heal "+target->QO+" completely.");
            tell_object(target, YOU+" touches the tip of your nose and you are healed completely.");
            tell_room(place, YOU+" reaches out and touches the tip of "+target->QCN+"'s nose and heals "+target->QO+" completely.",({ caster, target}) );
        }
    } 
    else 
    { 
        // OBJECT CALLS HEAL
        tell_room(environment(caster), caster->QCN+" sends a beam of energy to "+target->QCN+"'s nose and heals "+target->QO+".",({ caster, target }) );
        tell_object(target, caster->QCN+" sends a beam of energy to you nose nose and heals you.");
    }

    rnd = - sdamage * 3/2;
    damage_targ(target,target->return_target_limb(),rnd,"positive energy");
    target->remove_paralyzed();
    target->set_poisoning((-1)*(int)target->query_poisoning());
    dest_effect();
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
