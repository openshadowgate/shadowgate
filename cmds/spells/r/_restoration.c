#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("restoration")
    set_spell_level(([ "oracle" : 2, "cleric" : 2,"inquisitor":2,"paladin":1, "druid":2 ]));
    set_mystery("life");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS restoration on TARGET");
    set_damage_desc("removes fatigue, exhaustion, confusion");
    set_description("This spell eliminates fatigue and exhaustion. It also clears target's confusion and restores their stamina.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
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
        cast = ""+caster->QCN+" folds "+caster->QP+
            " hands as "+caster->QS+" prays for a divine spell!\n";
    }
    else
    {
        cast = ""+caster->QCN+" calls for a divine spell!\n";
    }
    return "\n"+cast;
}
 
spell_effect(int prof)
{
    int rnd;

    tell_object(target,"You feel invigorated and restored as the energy washes over you.");
    tell_room(ENV(target),target->QCN+" looks invigorated and restored.");

    if(member_array(target,caster->query_attackers())==-1)
        "/std/magic/cleanse"->restore(target);

    target->use_stamina(-target->query_max_stamina()/2);
 
    dest_effect();
}
 
void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
