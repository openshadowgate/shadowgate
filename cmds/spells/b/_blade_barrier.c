#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("blade barrier");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS blade barrier");
    set_description("This spell surrounds the caster in a protective whirlwind of spinning, razor sharp blades.  The "
"blades will follow the caster wherever they go and inflict damage on any enemies that get too close.  The amount of "
"blades in the air depends on the level of the caster.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^CYAN%^Invoking a quick prayer, "+
		"you curl your fingers as you extend your hands outwards.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" begins to "+
               "invoke a quick prayer as "+caster->QP+" fingers curl "+
		"while "+caster->QS+" extends "+caster->QP+" hands outwards.",caster);
    return "display";
}

int preSpell(){
    if(caster->query_property("blade barrier")){
        tell_object(caster,"You are already protected by a blade barrier.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int duration; 
    duration = (ROUND_LENGTH * 10) * clevel; // Might need tweaked -Ares
     tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" growls an incantation to "+caster->QP+" deity "
       "and the sound of thousands of whirling blades fills the air as "
        ""+caster->QS+" is encased in a protective barrier of blades!",caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^You growl an incantation to your deity and the sound "
        "of thousands of whirring blades surrounds you as you are encased "
        "in their protective barrier!.");
    caster->set_property("spelled", ({TO}));
    caster->set_property("blade barrier",1);
    caster->set_property("added short",({"%^CYAN%^ (encircled by blades)%^RESET%^"}));
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
    attackers   = target_filter(attackers);
    max         = clevel/10;
    attacks     = clevel;
    place       = environment(caster);
    if(sizeof(caster->query_classes()) > 1){
        max     = max/2;
        attacks = attacks/2;
    }
    
    if(!random(10)){
        tell_room(place,"%^CYAN%^Thousands of tiny razor sharp blades dance in a "
            "whirlwind around "+caster->QCN+"!",caster);
        tell_object(caster,"%^CYAN%^Thousands of tiny razor sharp blades dance in a "
            "whirlwind around you!");
    }
    if(!sizeof(attackers)){
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) { continue; }
        tell_object(caster,"%^BOLD%^%^BLACK%^Your spinning blades tear into "+attackers[i]->QCN+" as "
            "they get too close!");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+"'s spinning blades tear into "+attackers[i]->QCN+" as "
            ""+attackers[i]->QS+" gets too close!",caster);
        hits = (max / 2) + (roll_dice(1,(max/2))); // hit at least half of the max times
        attacks -= hits;
        if(attacks < 0)     { attacks = 0; }
        if(hits < attacks)  { hits = attacks; }
        define_base_damage(0);
        for(j=0;j<max;j++){
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"slashing");
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

void dest_effect()
{
    if(objectp(caster)){ 
        tell_room(environment(caster),"%^CYAN%^The spinning blades surrounding "+caster->QCN+" slow "
            "and then dissipate.",caster);
        tell_object(caster,"%^CYAN%^The spinning blades surrounding you slow and then fade away.");
        caster->remove_property("blade barrier"); 
	    caster->remove_property_value("added short",({"%^CYAN%^ (encircled by blades)%^RESET%^"}));    
    }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
