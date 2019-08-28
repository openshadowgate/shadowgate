#include <priest.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("pator");
    set_spell_name("cure serious wounds");
    set_spell_level(([ "cleric" : 3, "bard" : 3, "paladin" : 3, "ranger" : 3,"druid" : 4 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure serious wounds on TARGET");
    set_description("This spell cures a large amount of wounds on one of "
        "the target's limbs.  It won't revive dead limbs.  The spell's "
        "power will increase as the caster continues to gain strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_helpful_spell(1);
}


string query_cast_string()
{
    string cast;

    if (interactive(caster))
    {
        cast = "%^CYAN%^"+YOU+" starts to mumble a long worshipful incantation!";
    }
    else
    {
        cast = "%^CYAN%^"+YOU+" starts to vibrate and a long worshipful"+
            " incantation to "+MINE+" deity sounds!";
    }
    return cast;
}


void spell_effect(int prof)
{
    tell_room(place,"%^CYAN%^A solid field radiates inward toward"+HIM+"!",({caster,target}));

    if(interactive(caster))
    {
        if (target!=caster)
        {
             tell_object(caster,"%^CYAN%^You restore a good portion of life "+
                        "energy to "+HIM+"!");
        }
    }
    tell_object(target,"%^CYAN%^A solid aura pulses from "+caster->QCN+" towards you,"+
        " restoring substantial bit of strength.");
    damage_targ(target, target->return_target_limb(), -sdamage, "positive energy");
    spell_successful();
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
