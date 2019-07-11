// hellfire warlock port of blade barrier
#include <priest.h>
#include <magic.h>
#include <spell.h>
inherit SPELL;

void create(){
    ::create();
    set_spell_name("hellfire shield");
    set_spell_level(([ "warlock" : 3 ]));
    set_syntax("cast CLASS hellfire shield");
    set_description("This spell surrounds the warlock with a searing barrier of hellfire, which will move with the "
"caster and harm any foes that get too close.  The strength of the flames depends on the level of the caster.\n\n"
"Only a hellfire warlock may harness this invocation.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^RED%^Blazing heat floods your veins as you invoke the infernal arts.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s eyes blaze with inner fire.",caster);
    return "display";
}

int preSpell(){
    if(caster->query_property("blade barrier")){
        tell_object(caster,"You are already protected by a barrier.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int duration; 
    duration = (ROUND_LENGTH * 10) * clevel; // Might need tweaked -Ares
     tell_room(place,"%^BOLD%^%^BLACK%^A sphere of b%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^leful fla%^BOLD%^%^RED%^m%^BOLD%^%^BLACK%^e roars to life around "+caster->QCN+", heat radiating against your skin!%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^B%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^leful fla%^BOLD%^%^RED%^m%^BOLD%^%^BLACK%^es roar to life around you, their fury focussed outwards!%^RESET%^");
    caster->set_property("spelled", ({TO}));
    caster->set_property("blade barrier",1);
    caster->set_property("added short",({"%^RED%^ (wreathed in ominous flames)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
    return;
}

// Works differently from the book version since I didn't want it to be another wall of fire
// The blades reach out and touch anybody that's attacking the caster, hitting them a max
// amount of times each equal to 1/10th of the caster's level until a total of caster
// level attacks have been executed.  It will stop if it runs out of attacks or if no targets
// are left who haven't already been hit.

void execute_attack(){
    object *attackers = ({});
    int attacks,max,damage,hits,i,j;
    if(!objectp(caster)) { dest_effect(); return; }
    if(!objectp(place))  { dest_effect(); return; }

    ::execute_attack();
    if(!objectp(caster)) { dest_effect(); return; }
    attackers   = caster->query_attackers();
    max         = clevel/10;
    attacks     = clevel;
    place       = environment(caster);
    if(sizeof(caster->query_classes()) > 1){
        max     = max/2;
        attacks = attacks/2;
    }
    
    if(!random(10)){
        tell_room(place,"%^RESET%^%^RED%^"+caster->QCN+"'s blazing shield pulses and surges with radiant energy!",caster);
        tell_object(caster,"%^RESET%^%^RED%^Your blazing shield pulses and surges with radiant energy!");
    }
    if(!sizeof(attackers)){
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    define_base_damage(0);//lazy re-roll
    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) { continue; }
        tell_object(caster,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" gets a little too close to you, and your hellish shield burns "+attackers[i]->QO+" horribly!");
        tell_room(place,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" gets a little too close to "+caster->QCN+", and the hellish shield burns "+attackers[i]->QO+" horribly!",caster);
        hits = (max / 2) + (roll_dice(1,(max/2))); // hit at least half of the max times
        attacks -= hits;
        if(attacks < 0)     { attacks = 0; }
        if(hits < attacks)  { hits = attacks; }
        for(j=0;j<max;j++){
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"untyped");
        }
    }
    if(attacks == 0){
       dest_effect();
       return;
    }
//This spell didn't end when it was out of attacks
//like it was supposed to.  Adding the above to see 
//if that will do it.  ~Circe~ 6/2/08
    place->addObjectToCombatCycle(TO,1);
    return;
}

void dest_effect(){
    if(objectp(caster)){ 
        tell_room(environment(caster),"%^RED%^The infernal shield flickers and vanishes from around "+caster->QCN+".",caster);
        tell_object(caster,"%^RED%^Your infernal shield flickers and then vanishes.");
        caster->remove_property("blade barrier"); 
	    caster->remove_property_value("added short",({"%^RED%^ (wreathed in ominous flames)%^RESET%^"}));    
    }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
