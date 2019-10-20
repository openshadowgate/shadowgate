#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("boneshaker");
    set_spell_level(([ "mage" : 2, "cleric" : 2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS boneshaker on TARGET");
    set_damage_desc("untyped to living, half to undead");
    set_description("Using a mental image of the target's external shell of skeleton, you shake it, causing target to undergo severe pain. This spell won't work on undead.");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" makes a cage out of "+TP->QP+" fingers while chanting intently.%^RESET%^";
}

void spell_effect(int prof)
{
    spell_successful();
    if(target->is_undead())
        sdamage/=2;
    tell_object(caster,"%^BOLD%^%^WHITE%^You will crushing of "+target->QCN+"'s internals!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" staggers in pain!", ({caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^Your bones ache of pain as the spell hits you!");
    damage_targ(target, target->query_target_limb(), sdamage,"untyped");
    spell_successful();
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
