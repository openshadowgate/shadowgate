#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int strikes;
int flag;

void create()
{
    ::create();
    set_spell_name("unholy aura");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("abjuration");
    set_sorc_bloodlines(({"abyssal"}));
    set_syntax("cast CLASS unholy aura");
    set_damage_desc("untyped, 2 AC");
    set_description("You are surrounded by an aura of evil that will harm all your opponents and will slightly protect you. This is nimbus-family spell that won't work with other nimbuses.");
    set_property("magic",1);
    traveling_aoe_spell(1);
    evil_spell(1);
}

int preSpell()
{
    if(caster->query_property("nimbus"))
    {
        tell_object(caster,"You are still affected by numbus.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You feel fell powers power warding you from the good!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" is suddenly surrounded by halo of darkness!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^BOLD%^%^BLACK%^ (in a fell halo)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    caster->add_ac_bonus(2);
    environment(caster)->addObjectToCombatCycle(TO,1);
    call_out("dest_effect",duration);
    return;
}

void execute_attack()
{
    object *attackers = ({}),targ;
    int i,damage;

    if(!objectp(caster))                        { dest_effect(); return; }
    if(!objectp(place = environment(caster)))   { dest_effect(); return; }
    if(!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if(!objectp(caster))                        { dest_effect(); return; }
    if(strikes > clevel)                        { dest_effect(); return; }

    if(!sizeof(attackers))
    {
        place->addObjectToCombatCycle(TO,1);
        return;
    }

    while(!objectp(targ) && (i < sizeof(attackers)))
    {
        targ = attackers[random(sizeof(attackers))];
        i++;
    }
    if(!objectp(targ))
    {
        place->addObjectToCombatCycle(TO,1);
        return;
    }

    define_base_damage(-9);

    tell_object(caster,"%^BOLD%^%^MAGENTA%^The darkness burns "+targ->QCN+" painfully!");
    tell_object(targ,"%^BOLD%^%^MAGENTA%^The halo around "+caster->QCN+"'s body burns your very soul!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^The halo around "+caster->QCN+" burns "+targ->QCN+"!",({targ,caster}));

    strikes++;
    damage_targ(targ,targ->return_target_limb(),damage,"untyped");

    place->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The halo around you fades.");
        caster->remove_property("nimbus");
        caster->add_ac_bonus(-2);
	    caster->remove_property_value("added short",({"%^BOLD%^%^BLACK%^ (in a fell)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
