#include <std.h>
#include <priest.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("vampiric shadow shield");
    set_spell_level(([ "mage" : 5,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS vampiric shadow shield");
    set_damage_desc("negative energy on living");
    set_description("You raise shadows of the undead to guard you from those who mean you harm. Any living that attacks you will be harmed and its life will be used to heal you.");
    set_save("reflex");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    return "%^BLUE%^As "+caster->QCN+" chants in low undertones shadows raise and surround "+caster->QO+".%^RESET%^";
}

int preSpell()
{
    if(caster->query_property("vampiric shadow shield"))
    {
        tell_object(caster,"You are already protected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 3) * clevel;
    tell_room(place,"%^BLUE%^"+caster->QCN+" completes "+caster->QP+" the chant and is surrounded by restless shadows.",caster);
    tell_object(caster,"%^BLUE%^You complete your chant and are surrounded by restless shadows!");
    caster->set_property("vampiric shadow shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(2);
    caster->add_property("added short",({"%^BLUE%^ (%^BOLD^%^BLACK%^engulfed in shadows%^RESET%^%^BLUE%^)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    call_out("dest_effect",duration);
}

void execute_attack()
{
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    if(!sizeof(attackers))
    {
        room->addObjectToCombatCycle(TO,1);
        return;
    }
    for(i=0;i<sizeof(attackers);i++)
    {
        if(do_save(attackers[i],0))
            continue;
        if(attackers[i]->is_undead())
            continue;
        tell_room(room,"%^BOLD%^%^BLUE%^Shadows around "+caster->QCN+" caress "+attackers[i]->QCN+"  as "+attackers[i]->QS+" strikes "+caster->QO+"!",({caster,target}));
        tell_object(caster,"%^BOLD%^%^BLUE%^%^"+attackers[i]->QCN+" is caressed by the shield of shadows as "+attackers[i]->QS+" strikes you!");
        tell_object(attackers[i],"%^BOLD%^%^BLUE%^You are caressed by the shield of shadows as you strike "+caster->QCN+"!");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage/2,"negative energy");
        damage_targ(caster,caster->return_target_limb(),-sdamage/2,"untyped");
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^BLUE%^The shadows retreat, leaving "+caster->QCN+" vulnerable once again.",caster);
        caster->remove_property("vampiric shadow shield");
        caster->add_ac_bonus(-2);
        caster->remove_property("added short",({"%^BLUE%^ (%^BOLD^%^BLACK%^engulfed in shadows%^RESET%^%^BLUE%^)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
