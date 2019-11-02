#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int flag;
int strikes;
int lastattack;

void create()
{
    ::create();
    set_spell_name("sacred nimbus");
    set_spell_level(([ "cleric" : 5, "paladin" : 4 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS sacred nimbus");
    set_damage_desc("divine to evil");
    set_description("You are surrounded by a nimbus of golden light shaped like your god's holy symbol or a symbol of your faith. Any evil creature attacking you will be burned by the light.");
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
    attackers = filter_array(caster->query_attackers(),(:
                                                        $1->query_alignment() == 3 ||
                                                        $1->query_alignment() == 6 ||
                                                        $1->query_alignment() == 9
                                                        :));
    if(lastattack == time())
        return;
    room->addObjectToCombatCycle(TO,1);
    lastattack = time();
    if(!sizeof(attackers))
        return;
    define_base_damage(0);
    tell_room(room,"%^BOLD%^%^ORANGE%^The light around "+caster->QCN+" falls upon "+caster->QP+" enemies!",({caster,target}));
    tell_object(caster,"%^BOLD%^%^ORANGE%^The light around you falls upon your enemies!");
    for(i=0;i<sizeof(attackers);i++){
        if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
        tell_object(attackers[i],"%^BOLD%^%^ORANGE%^You are burned by the light as you strike "
            ""+caster->QCN+"!");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"divine");
    }
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The halo around you fades.");
        caster->remove_property("nimbus");
	    caster->remove_property_value("added short",({"%^YELLOW%^ (in halo of light)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
