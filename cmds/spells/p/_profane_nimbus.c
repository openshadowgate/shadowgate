#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int strikes;

void create()
{
    ::create();
    set_spell_name("profane nimbus");
    set_spell_level(([ "cleric" : 5, "paladin" : 4 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS profane nimbus");
    set_damage_desc("divine to good");
    set_description("You are surrounded by a nimbus of darkness shaped like your god’s holy symbol or a symbol of your faith. Any good creature attacking you will be scorched by the darkness.");
    set_property("magic",1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^MAGENTA%^You growl a quiet plea to your divine patron.");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" growls a quiet plea under "+caster->QP+" breath.",caster);
    return "display";
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

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You feel your gods power warding you from the good!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" is suddenly surrounded by halo of darkness!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^BOLD%^%^MAGENTA%^ (in halo of darkness)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
    return;
}

void execute_attack()
{
    object *attackers = ({}),targ;
    int i,damage;

    if(!objectp(caster))                        { dest_effect(); return; }
    if(!objectp(place = environment(caster)))   { dest_effect(); return; }
    ::execute_attack();
    if(!objectp(caster))                        { dest_effect(); return; }
    if(strikes > clevel)                        { dest_effect(); return; }

    attackers = filter_array(caster->query_attackers(),(:
                                                        $1->query_alignment() == 1 ||
                                                        $1->query_alignment() == 4 ||
                                                        $1->query_alignment() == 7
                                                        :));

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
    damage_targ(targ,targ->return_target_limb(),damage,"divine");

    place->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The halo around you fades.");
        caster->remove_property("nimbus");
	    caster->remove_property_value("added short",({"%^BOLD%^%^MAGENTA%^ (in halo of darkness)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
