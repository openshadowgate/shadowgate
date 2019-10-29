#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int strikes;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("call lightning storm");
    set_spell_level(([ "druid" : 5 ]));
    set_spell_sphere("combat");
    set_save("reflex");
    set_syntax("cast CLASS call lightning storm");
    set_description("This spell will cause the caster to become charged with static electricity.  The electricity will occasionally "
        "discharge at one of the caster's enemies, hitting him or her with a powerful blast of lightning.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^YELLOW%^You growl a quiet plea to the forces of nature.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" growls a quiet plea under "+caster->QP+" breath.",caster);
    return "display";
}


int preSpell()
{
    if(caster->query_property("call lightning storm"))
    {
        tell_object(caster,"You are still affected by call lightning storm.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel; // Might need tweaked -Ares

    tell_object(caster,"%^YELLOW%^Your eyes suddenly snap open wide as you feel the cr%^RESET%^a%^BOLD%^c%^YELLOW%^k%^RESET%^%^YELLOW%^le "
        "of static energy fill your body!");
    tell_room(place,"%^YELLOW%^"+caster->QCN+"'s eyes suddenly snap open wide and you can see electricity "
        "dancing dangerously in them!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("call lightning storm",1);
    caster->set_property("added short",({"%^YELLOW%^ (crackling with electrical energy)%^RESET%^"}));
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
    if(strikes > clevel)                        { dest_effect(); return; } // one lightning strike per level

    if(!random(15))
    {
        tell_room(place,"%^YELLOW%^Electricity pops and crackles, dancing in the air around "+caster->QCN+"!",caster);
        tell_object(caster,"%^YELLOW%^Electricity pops and crackles, dancing in the air around you!");
    }

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
    place->addObjectToCombatCycle(TO,1);
    if(!objectp(targ))
        return;

    damage = sdamage;
    if(!do_save(targ))
    {
        tell_object(caster,"%^BOLD%^%^YELLOW%^A bolt of electricity leaps out from your body and zaps "+targ->QCN+" painfully!");
        tell_object(targ,"%^BOLD%^%^YELLOW%^A bolt of electricity leaps out from "+caster->QCN+"'s body and zaps you square in the chest!");
        tell_room(place,"%^BOLD%^%^YELLOW%^A bolt of electricity leaps out from "+caster->QCN+"'s body and zaps "+targ->QCN+" square in the chest!",({targ,caster}));

        strikes++;
        damage_targ(targ,targ->return_target_limb(),damage,"electricity");
    }
    else
    {
        tell_object(caster,"%^RESET%^%^BOLD%^A bolt of electricity leaps out from your body and "+targ->QCN+" turns at the last moment, avoiding most of the damage!");
        tell_object(targ,"%^RESET%^%^BOLD%^A bolt of electricity leaps out from "+caster->QCN+"'s body and you barely turn aside at the last instant, avoiding most of the damage!");
        tell_room(place,"%^RESET%^%^BOLD%^A bolt of electricity leaps out from "+caster->QCN+"'s body and "+targ->QCN+" barely turns aside at the last instant, avoiding most of the damage!",({targ,caster}));

        strikes++;
        damage_targ(targ,targ->return_target_limb(),damage/2,"electricity");
    }

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
