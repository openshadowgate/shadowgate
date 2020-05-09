// Darkbolt
//Minor chages by ~Circe~ and switched to level 5
//with the domain rebalancing 4/25/08
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("darkbolt");
    set_spell_level(([ "mage" : 5 ]));
    set_spell_sphere("necromancy");
    set_domains("darkness");
    set_syntax("cast CLASS darkbolt on TARGET");
    set_damage_desc("half cold, half electricity");
    set_description("This spell will hurl a bolt of pure evil at the target.  If the target is able to move in time, then "
"they will only suffer some of the damage.  This spell may also hit some of those who are standing near the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^BLACK%^%^You chant in a secretive whisper,"+
		" and the shadows swirl around you, congregating in your palms.");
    tell_room(place,"%^BOLD%^%^BLACK%^The shadows swirl around "+caster->QCN+","+
		" congregating in "+caster->QP+" palms.",({ caster }) );
    return "display";
}

void spell_effect(int prof){
    int damage,i;
    object *attackers;

    if(!present(target,place)){
        tell_object(caster,"Your target has left.");
        dest_effect();
        return;
    }

    attackers = target_selector();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    attackers += ({ target });
    attackers = distinct_array(attackers);

    damage = sdamage;

    tell_object(caster,"%^BOLD%^%^BLACK%^You hurl your fist towards "+target->QCN+" and a beam of "
        "darkness flows forth towards "+target->QO+".");
    tell_object(target,"%^BOLD%^%^BLACK%^A beam of darkness flows forth from "+caster->QCN+"'s "
        "hand towards you!");
    tell_room(place,"%^BOLD%^%^BLACK%^"+ caster->QCN+" hurls "+caster->QP+" fist forth and a beam "
        "of darkness flows towards "+target->QCN+"!",({ caster, target}) );
    if(sizeof(attackers)){
        for(i=0;i<sizeof(attackers);i++){
            if(!objectp(attackers[i])) { continue; }
            if(attackers[i] == target){
                if(!do_save(target,0)) {
               //if (!SAVING_D->saving_throw(target, "spell")){
                  tell_object(target,"%^BLUE%^The beam of darkness strikes you, ravaging your mind.");
                  tell_room(environment(target),"%^BLUE%^The beam of darkness strikes "+target->QCN+".", target);
                  damage_targ(target, "torso", damage/2,"cold");
                  damage_targ(target, "torso", damage/2,"electricity");
                  spell_kill(target,caster);
              }else{
                  tell_object(target,"%^BLUE%^The beam grazes you.");
                  tell_room(environment(caster),"%^BLUE%^The beam almost misses "+target->QCN+".",target);
                  damage_targ(target, "torso", damage/2,"cold");
                  spell_kill(target,caster);
              }
           }else{
               if(!do_save(target,0)) {
              //if(!SAVING_D->saving_throw(target,"spell")){
                 tell_object(attackers[i],"%^BLUE%^The beam of darkness "+
                    "aimed at "+target->QCN+" tears through you!%^RESET%^");
                 tell_room(environment(caster),"%^BLUE%^The beam of "+
                    "darkness tears through "+
                    ""+attackers[i]->QCN+"!%^RESET%^",attackers[i]);
                  damage_targ(target, "torso", damage/2,"cold");
                  damage_targ(target, "torso", damage/2,"electricity");
                 spell_kill(target,caster);
              }else{
                 tell_object(attackers[i],"%^BLUE%^The beam of darkness "+
                    "aimed at "+target->QCN+" grazes you!%^RESET%^");
                 tell_room(environment(caster),"%^BLUE%^The beam of "+
                    "darkness grazes "+
                    ""+attackers[i]->QCN+"!%^RESET%^",attackers[i]);
                  damage_targ(target, "torso", damage/2,"cold");
                 spell_kill(target,caster);
              }
           }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
