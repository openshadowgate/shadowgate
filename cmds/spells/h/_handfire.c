//Handfire - was 2nd level, brought up to be a bolt at level 5
//Made 5th level to bring in line with the other bolt spells
//during the domain rebalancing ~Circe~ 5/11/08
// switched to 3e save system. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("handfire");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("elemental fire");
    set_spell_domain("fire");
    set_syntax("cast CLASS handfire on TARGET");
    set_description("Calling on the endless inferno of the plane of elemental fire, the priest is able to wrap his hand "
                    "with crimson flames.  The priest then sends forth the flames to strike his target, possibly burning those in the way as "
                    "well.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
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
    tell_room(place, "%^RED%^Crimson flames spiral around "+caster->QCN+"'s"+
              " hand as "+caster->QS+" calls for aid!",caster);    
    tell_object(caster,"%^RED%^Crimson flames spiral around your hand as you"+
                " call for aid.%^RESET%^");
    return "display";
}

spell_effect(int prof){
    object *attackers;
    int i,damage;

    if (!present(target,place)){
        tell_object(caster,"%^BOLD%^Your target is not in this area.");
        dest_effect();
        return 1;
    }
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    attackers += ({ target });
    attackers = distinct_array(attackers);

    if(sizeof(attackers)){
        for(i=0;i<sizeof(attackers);i++){
            define_base_damage(0);
            damage = sdamage;
            if(!objectp(attackers[i])) { continue; }
            if(attackers[i] == target){
                tell_object(target, "%^RED%^The crimson flames around "+
                            ""+caster->QCN+"'s hand blazes through your defenses "+
                            "and into your mind.%^RESET%^");
                tell_object(caster,"%^RED%^The crimson flames around "+
                            "your hand blazes through "+target->QCN+"'s defenses "+
                            "and into "+target->QP+" mind.%^RESET%^");
                tell_room(place,"%^RED%^The crimson flames around "+
                          ""+caster->QCN+"'s hand blazes through "+
                          ""+target->QCN+"'s defenses.%^RESET%^",({caster,target}));
                spell_kill(attackers[i],caster);
                if(!do_save(attackers[i],-2))
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"fire");
                else
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"fire");
            }else{
                if(!do_save(attackers[i],-2)) {
                    tell_room(place,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" "+
                              "is burned by the flames!%^RESET%^",attackers[i]);
                    tell_object(attackers[i],"%^BOLD%^%^RED%^The flames "+
                                "burn into you as well!%^RESET%^");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"fire");
                    spell_kill(attackers[i],caster);
                }else{
                    tell_room(place,"%^ORANGE%^"+attackers[i]->QCN+" is singed "+
                              "by the flames as they pass!%^RESET%^",attackers[i]);
                    tell_object(attackers[i],"%^ORANGE%^The heat of the flames "+
                                "singes you as it passes!%^RESET%^");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"fire");
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
