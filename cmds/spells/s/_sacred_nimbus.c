#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int strikes;

void create()
{
    ::create();
    set_spell_name("sacred nimbus");
    set_spell_level(([ "cleric" : 5, "paladin" : 4 ]));
    set_spell_sphere("combat");
    set_save("reflex");
    set_syntax("cast CLASS sacred nimbus");
    set_damage_desc("divine to evil");
    set_description("You are surrounded by a nimbus of golden light shaped like your god’s holy symbol or a symbol of your faith. Any evil creature attacking you will be burned by the light.");
    set_property("magic",1);
    traveling_aoe_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^YELLOW%^You growl a quiet plea to your divine patron.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" growls a quiet plea under "+caster->QP+" breath.",caster);
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

    tell_object(caster,"%^YELLOW%^You feel your gods power warding you from the evil!");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" is suddenly surrounded by halo of light!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^YELLOW%^ (in halo of light)%^RESET%^"}));
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

    attackers = caster->query_attackers();

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

        tell_object(caster,"%^BOLD%^%^YELLOW%^The light burns "+targ->QCN+" painfully!");
        tell_object(targ,"%^BOLD%^%^YELLOW%^The halo around "+caster->QCN+"'s body burns your very soul!");
        tell_room(place,"%^BOLD%^%^YELLOW%^The halo around "+caster->QCN+" burns "+targ->QCN+"!",({targ,caster}));

        strikes++;
        damage_targ(targ,targ->return_target_limb(),damage,"divine");

    place->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^With a final loud pop, the electrical energy coursing through your "
            "body dissipates in an instant.");
        tell_room(environment(caster),"%^RESET%^%^BOLD%^With a final loud pop, the electrical energy coursing through "
            ""+caster->QCN+"'s body dissipates in an instant.",caster);
        caster->remove_property("call lightning storm");
	    caster->remove_property_value("added short",({"%^YELLOW%^ (crackling with electrical energy)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
