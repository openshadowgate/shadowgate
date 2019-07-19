//Lion's Charge
//Psywarrior attack spell ~Circe~ 9/29/15

#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("headbutt");
    set_spell_level(([ "innate" : 1 ]));
    set_syntax("cast innate headbutt on TARGET");
    set_description("A satyress can charge someone with her horns any time she wishes. The power of her charge will depend on her strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    object *weapons, myweapon;
    int bonus, enchant, damage;
    if(!objectp(target)){
       tell_object(caster,"You don't see that here!");
       dest_effect();
       return;
    }
    if(target == caster){
       tell_object(caster,"Don't try to charge yourself!");
       dest_effect();
       return;
    }
    if (interactive(caster)) {
        tell_object(caster,"%^RESET%^%^BOLD%^You incline your head toward "+target->QCN+" and charge!%^RESET%^");
    }
    tell_object(target,"%^RESET%^%^BOLD%^"+caster->QCN+" charges toward you with intention to headbutt!%^RESET%^");
    tell_room(place,"%^RESET%^%^BOLD%^"+caster->QCN+" charges toward "+target->QCN+"!%^RESET%^", ({caster, target}) );
    if(!thaco(target)){
        tell_object(caster,"%^BOLD%^%^RED%^You charge straight past "
           ""+target->QCN+", missing "+target->QO+" entirely!%^RESET%^");
        tell_object(target,"%^BOLD%^%^RED%^You sidestep, avoiding "+caster->QCN+"'s charge!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+target->QCN+" sidesteps, "
           "avoiding "+caster->QCN+"'s charge!%^RESET%^", ({caster, target}));
        spell_successful();
        dest_effect();
        return;
    }
    damage = roll_dice(6,clevel); 
    damage += "/daemon/bonus_d"->damage_bonus(caster->query_stats("strength"));
    damage += (int)caster->query_damage_bonus();

    tell_object(caster,"%^WHITE%^%^BOLD%^You pounce on "+target->QCN+", knocking "
       ""+target->QO+" to the ground!%^RESET%^");
    tell_object(target,"%^WHITE%^"+caster->QCN+" pounces on you, knocking "
       "you to the ground!%^RESET%^");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" pounces on "+target->QCN+", "
       "knocking "+target->QO+" to the ground!%^RESET%^", ({caster, target}));

    if(target->is_npc() || userp(target)) {
      if(target->query_deaths_door() && (userp(caster) || caster->query_property("knock unconscious"))) {
        target->cease_all_attacks();
        target->remove_attacker(caster);
        caster->remove_attacker(target);
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" falls unconscious "+
          "after you slam into "+target->QO+"!");
     	  tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" slams "+
          "full force into "+target->QCN+", knocking "+target->QO+" completely "+
          "unconscious due to wounds!",({target,caster}));
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" slams full force "+
          "into you, knocking you unconscious.\n");
      }
    }
    damage_targ(target, target->query_target_limb(), damage, "force");
    spell_successful();
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
