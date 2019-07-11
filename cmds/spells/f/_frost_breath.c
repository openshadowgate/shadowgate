//Switching with Ice Shield, so this will be level 5.
//This is way too good to be a 2nd level :)  Rebalancing 
//the domains ~Circe~ 5/5/08
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("frost breath");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("weather");
    set_spell_domain("cold");
    set_syntax("cast CLASS frost breath on TARGET");
    set_description("This spell sends a wave of cold shards out in a cone shapped pattern from the caster's cupped hands"
".  It will hit any enemies who are not able to get out of the way.  The extreme cold can sometimes damage enemies who "
"remain in the area of cold even after the initial hit.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);    
    set_immunities(({"cold"}));
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
    tell_object(caster,"%^BOLD%^%^CYAN%^Cupping your hands together, you "+
		"exhale forcefully across them.");
    tell_room(place,"%^BOLD%^%^CYAN%^Cupping "+caster->QP+" hands together,"+
		" "+caster->QCN+" exhales forcefully across them.",caster);
    return "display";
}

void spell_effect(int prof){
    object *attackers;
    int i,damage;

    if(!present(target,place)){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers += ({ target });
    attackers = distinct_array(attackers);
    attackers = target_filter(attackers);

    if(sizeof(attackers)){
      for(i=0;i<sizeof(attackers);i++)
      {
        define_base_damage(0);
        damage = sdamage;
        if(!objectp(attackers[i])) { continue; }
        spell_kill(attackers[i],caster);
        if(attackers[i] == target){
          tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s breath shoots forth"+
                      " tinged with frost and crystals of ice, draining the heat from you!");
          tell_object(caster,"%^BOLD%^%^CYAN%^Your breath shoots forth, tinged with frost"+
                      " and crystals of ice, striking "+target->QCN+"!");
          tell_room(place, "%^BOLD%^%^CYAN%^"+caster->QCN+"'s breath shoots forth, "+
                    "tinged with frost and crystals of ice, draining the heat from "+
                    ""+target->QCN+".",({ caster, target}) );
          spell_kill(attackers[i],caster);
          if(!do_save(attackers[i],0))
            //if(!SAVING_D->saving_throw(attackers[i],"spell",0))                
            attackers[i]->do_damage(attackers[i]->return_target_limb(),damage,"cold");                
          else                 
            attackers[i]->do_damage(attackers[i]->return_target_limb(),damage/2,"cold");                
        }
        else
        {
          if(!do_save(attackers[i],0)) {
            //if(!SAVING_D->saving_throw(attackers[i],"spell",0)){
            tell_room(place,"%^BOLD%^%^CYAN%^"+attackers[i]->QCN+" is chilled by the "
                      "shards of ice!",attackers[i]);
            tell_object(attackers[i],"%^BOLD%^%^CYAN%^You are chilled by the ice.");
            attackers[i]->do_damage(attackers[i]->return_target_limb(),damage,"cold");
            spell_kill(attackers[i],caster);
          }else{
            tell_room(place,"%^CYAN%^"+attackers[i]->QCN+" jumps out of the way just"+
                      " as the frosty breath about to hit!",attackers[i]);
            tell_object(attackers[i],"%^CYAN%^You are only slightly chilled by the cold.");
            attackers[i]->do_damage(attackers[i]->return_target_limb(),damage/2,"cold");
            spell_kill(attackers[i],caster);
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
