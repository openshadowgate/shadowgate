//Rejuvenation - new spell for the Renewal domain by
//~Circe~ based on Regeneration by Ares
//part of the rebalancing of domains
//Note that this spell *will* be able to stack with regeneration

#include <std.h>
#include <clock.h>

inherit SPELL;

int duration;

void create(){
    ::create();
    set_spell_name("rejuvenation");
    set_spell_level(([ "cleric" : 3 ]));
    set_spell_sphere("healing");
    set_spell_domain("renewal");
    set_syntax("cast CLASS rejuvenation");
    set_description("This spell will grant the caster the power of renewal, giving him a small amount of healing each "
"round for a long period of time.");
    set_verbal_comp();
    set_property("magic",1);
	set_helpful_spell(1);
}

string query_cast_string(){
   tell_object(caster,"%^ORANGE%^With a touch of your holy symbol, you "+
      "begin a worshipful prayer to "+(string)caster->query_diety()+" "+
      "to help heal you.%^RESET%^");
   tell_room(place,"%^ORANGE%^"+caster->QCN+" touches "+caster->QP+" "+
      "holy symbol and calls upon "+caster->QP+" deity's "+
      "blessings!%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    duration = (clevel * HOUR)/25;
    if(duration > (HOUR)) { duration = HOUR; } // max duration of 1 game hour
    duration = time() + duration; // gives the exact second when the spell should end

    tell_room(place,"%^ORANGE%^A %^BOLD%^radiant light %^RESET%^%^ORANGE%^"+
       "bathes "+caster->QCN+" briefly!",caster);
    tell_object(caster,"%^ORANGE%^You feel warmth as a %^BOLD%^radiant "+
       "light %^RESET%^%^ORANGE%^surrounds you briefly!%^RESET%^");
    caster->set_property("spelled", ({TO}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack(){
    int hp,max_hp;
    object room;

    if(!objectp(caster)) { dest_effect(); return; }

    ::execute_attack();
    if((time()) > duration){
        tell_object(caster,"%^ORANGE%^You feel cold as the warmth of "+
           "the light leaves you.%^RESET%^");
        dest_effect();
        return;
    }
    hp     = (int)caster->query_hp();
    max_hp = (int)caster->query_max_hp();
//    room   = environment(caster);
//Moving these to a no_clean room to see if it stops bugs
//~Circe~ 6/1/08
    room = "/d/magic/room/regen_room";
    if(hp >= max_hp){
        room->addObjectToCombatCycle(TO,1);
        return;
    }
/*
    if(caster->query_property("berserked")){
        tell_object(room,"The berserker rage fights off the healing.");
        room->addObjectToCombatCycle(TO,1);
        return;
    }
Removing to help balance Berserker (level 7 domain spell) ~Circe~ 5/17/13
*/
    tell_object(caster,"%^ORANGE%^The light adds a bit of strength to you!%^RESET%^");
    caster->add_hp(roll_dice(1,6));
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
