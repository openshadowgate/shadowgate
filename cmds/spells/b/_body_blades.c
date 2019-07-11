// body blades
#include <std.h>
#include <priest.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("body blades");
    set_spell_level(([ "cleric" : 2 ]));
    set_spell_sphere("combat");
    set_spell_domain("suffering");
    set_syntax("cast CLASS body blades");
    set_description("This spell will cause razor sharp blades to sprout from the caster's skin, protecting them from harm "
"and doing damage to anyone who attacks the caster.");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string() 
{
   	tell_object(caster,"%^RED%^Rubbing some iron shavings onto your skin,"+
		" you begin to chant in a low growl.");
	tell_room(place,"%^RED%^"+caster->QCN+" rubs some iron shavings onto"+
		" "+caster->QP+" skin as "+caster->QS+" chants in a low growl.",caster);
    return "display";
}

int preSpell() 
{
    if(caster->query_property("body blades")) 
    {
        tell_object(caster,"You are already protected by body blades.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) 
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;
    tell_room(place,"%^RED%^Tiny blades push out of "+caster->QCN+"'s flesh as "
        ""+caster->QS+" completes "+caster->QP+" prayer!");
    tell_object(caster,"%^RED%^You can feel a slight twinge of pain as blades "
        "pierce through your flesh!");
    caster->set_property("body blades",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(1);
    caster->set_property("added short",({"%^BOLD%^%^BLACK%^ (covered with blades)"}));
    addSpellToCaster();
    spell_successful();
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
    if(!sizeof(attackers))
    {
        room->addObjectToCombatCycle(TO,1);
        return;
    }
    for(i=0;i<sizeof(attackers);i++)
    {
    	tell_object(attackers[i],"%^BOLD%^%^RED%^You are cut by the blades that have sprouted "
            "from "+caster->QCN+"'s body!");
    	tell_object(caster,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" is cut by the blades that have "
            "sprouted from your body!");
     	tell_room(environment(attackers[i]),"%^BOLD%^%^RED%^"+attackers[i]->QCN+" is cut by the "
            "blades that have sprouted from "+caster->QCN+"'s body!",({target,caster}));
        damage_targ(attackers[i],attackers[i]->return_target_limb(),roll_dice(2,10),"slashing");
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RED%^The blades sink back into your flesh, leaving you "
            "vulnerable to attack once again.");
        tell_room(environment(caster),"%^RED%^The blades sink back into "+caster->QCN+"'s "
            "flesh, leaving "+caster->QO+" vulnerable once again.",caster);
        caster->remove_property("body blades");
        caster->add_ac_bonus(-1);
	    caster->remove_property_value("added short",({"%^BOLD%^%^BLACK%^ (covered with blades)"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}