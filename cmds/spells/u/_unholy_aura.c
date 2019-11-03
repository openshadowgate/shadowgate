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

void execute_attack(){
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = filter_array(caster->query_attackers());
    if(lastattack == time())
        return;
    room->addObjectToCombatCycle(TO,1);
    lastattack = time();
    if(!sizeof(attackers))
        return;
    define_base_damage(0);
    tell_room(room,"%^BOLD%^%^BLACK%^The darkness around "+caster->QCN+" falls upon "+caster->QP+" enemies!",({caster,target}));
    tell_object(caster,"%^BOLD%^%^BLACK%^The darkness around you falls upon your enemies!");
    for(i=0;i<sizeof(attackers);i++){
        if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
        tell_object(attackers[i],"%^BOLD%^%^BLACK%^You are scorched by the darkness as you strike "
            ""+caster->QCN+"!");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"untyped");
    }
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The halo around you fades.");
        caster->remove_property("nimbus");
        caster->add_ac_bonus(-2);
	    caster->remove_property_value("added short",({"%^BOLD%^%^BLACK%^ (in a fell halo)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
