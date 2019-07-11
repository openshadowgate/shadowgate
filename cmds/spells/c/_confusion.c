// Updated by ~Circe~ 5/11/08 for the rebalancing of domains
// Id Insinuation
// ~Circe~ 9/11/05
// Ganked for the priest spell confusion -Ares
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object mytarg;
int rnds,total;

void create(){
    ::create();
    set_spell_name("confusion");
    set_spell_level(([ "cleric" : 7, "bard":3,"mage":4 ]));
    set_spell_sphere("enchantment_charm");
    set_spell_domain("trickery");
    set_syntax("cast CLASS confusion on TARGET");
    set_description("This spell will attempt to confuse the target and make them do random things.  They might babble "
"incoherently, attack the closest thing to them, or simply wander away.  When used on a player, it simply causes them to "
"stand and stare blankly.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

int preSpell(){
    if(!target){
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int bonus;
    mytarg = target;
    bonus = clevel/6;
    bonus = -1*bonus;
    total = clevel/5;
    if(total < 0) total = 0;
    total += 3;

    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" gazes at you intently as "
        ""+caster->QS+" begins to chant!");
    tell_object(caster,"%^BOLD%^%^CYAN%^You gaze intently at "+target->QCN+" as "
        "you begin to chant!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" gazes at "+target->QCN+" intently "
        "as "+caster->QS+" begins to chant!",({caster,target}));

    if(do_save(mytarg,bonus))
    //if(do_saving_throw(mytarg,"spell",bonus))
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^"+target->QCN+" is able to resist the pull "
            "of your spell!");
        tell_object(target,"%^GREEN%^%^BOLD%^You are able to resist the pull of "+caster->QCN+"'s "
            "spell!");
        tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" shakes "+target->QP+" head and as "
            ""+caster->QCN+" completes "+caster->QP+" spell.",({caster,target}));
        if(!target->is_player()) { spell_kill(mytarg, caster); }
        TO->dest_effect();
        return;
    }else{
        
        if(mind_immunity_check(target, "default"))
        {
            target->add_attacker(caster);
            damage_targ(target, target->return_target_limb(), sdamage,"untyped");
            spell_successful();
            dest_effect();
            return;
        }
        
        if(target->is_player()){
            tell_object(target,"%^MAGENTA%^Your mind suddenly becomes overwhelmed with "
                "jumbled thoughts and images, and you stand confused!");
            tell_object(caster,""+target->QCN+" is overcome with confusion and "
                "stands staring into space!");
            tell_room(place,"%^MAGENTA%^"+target->QCN+" suddenly stares off into space as "
                ""+caster->QCN+" finishes "+caster->QP+" chant!",({target,caster}));
            target->set_paralyzed(roll_dice(1,clevel),"You are too confused to do anything!");
            dest_effect();
            return;
        }else{
            tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+"'s mind is muddled by the power "
                "of your spell!");
            tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" gets a strange look on "+target->QP+" face "
                "as "+caster->QCN+" completes "+caster->QP+" spell!",({caster,target}));
            rnds = 0;
            mytarg->set_property("spelled", ({TO}) );
            call_out("confuse_em",3,mytarg);
            spell_kill(mytarg, caster);
            spell_successful();
        }
    }
}

void confuse_em(object mytarg){
   int i;
   object *targs;
   object chosen;
   if(!objectp(mytarg)){
      TO->dest_effect();
      return;
   }
   if(!objectp(caster) || !present(caster,environment(mytarg))){
      TO->dest_effect();
      return;
   }
   if(rnds < total){
      switch(random(100)){
         case 0..10:  if(!present(caster,environment(mytarg))) TO->dest_effect();
                      mytarg->force_me("kill "+caster->query_name()+"");
                      tell_object(mytarg,"%^BOLD%^%^RED%^Outraged, "+
                          "you attack "+caster->QCN+"!");
                      tell_object(caster,"%^BOLD%^%^RED%^Outraged, "+
                          ""+mytarg->QCN+" attacks you!");
                      tell_room(environment(mytarg),"%^BOLD%^"+mytarg->QCN+" "+
                          "attacks "+caster->QCN+" in a violent rage!",({mytarg,caster}));
                      break;
         case 11..20: break;
         case 21..50: if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^YELLOW%^A strange thought "+
                          "enters your mind, but you cannot grasp it!");
                      tell_room(environment(mytarg),"%^YELLOW%^"+
                          ""+mytarg->QCN+" stares at a point in space, "+
                          "babbling incoherently!",mytarg);
                      mytarg->set_paralyzed(roll_dice(3,6),"You are trying to recall that thought!"); //was just 4
                      break;
/*
         case 51..70: if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^BOLD%^%^BLUE%^With a "+
                          "sudden, uncontrolled fright, you run away "+
                          "from "+caster->QCN+"!");
                      tell_object(caster,"%^BOLD%^%^BLUE%^"+mytarg->QCN+" "+
                          "looks at you in terror and tries to run away!");
                      tell_room(environment(mytarg),"%^BOLD%^%^BLUE%^"+
                          ""+mytarg->QCN+" casts a look of pure terror "+
                          "at "+caster->QCN+" and tries to flee!",({mytarg,caster}));
                      mytarg->run_away();
                      mytarg->run_away();
                      mytarg->run_away();
                      mytarg->run_away();
                      break;
Removed to make the spell a little more useful ~Circe~ 5/11/08
*/
         case 51..70: if(!present(caster,environment(mytarg))) TO->dest_effect();
                      tell_object(mytarg,"%^BOLD%^%^CYAN%^A sudden, "+
                         "overwhelming sense of drowsiness comes "+
                         "over you, and you fall asleep!%^RESET%^");
                      tell_room(environment(mytarg),"%^BOLD%^%^CYAN%^"+
                          ""+mytarg->QCN+" suddenly falls asleep on "+
                          ""+mytarg->QP+" feet!%^RESET%^",mytarg);
                      mytarg->set_asleep((clevel/4), "You are asleep!");
                      break;
         default:     if(!present(caster,environment(mytarg))) TO->dest_effect();
                      targs = all_living(environment(mytarg));
                      filter_array(targs, "is_non_immortal", FILTERS_D);
                      targs -= ({mytarg});
                      i = random(sizeof(targs));
                      chosen = targs[i];
                      tell_object(mytarg,"%^BOLD%^%^RED%^In a blind "+
                          "rage, you attack the thing closest to you!");
                      tell_object(chosen,"%^BOLD%^%^RED%^"+mytarg->QCN+" "+
                          "suddenly turns and swings wildly at you!");
                      tell_room(environment(mytarg),"%^BOLD%^%^RED%^"+
                          ""+mytarg->QCN+" suddenly turns and swings wildly, "+
                          "attacking "+chosen->QCN+"!",({mytarg, chosen}));
                      mytarg->force_me("kill "+chosen->query_name()+"");
                      break;
      }
      rnds++;
      call_out("confuse_em",5,mytarg);
      return;
   }
   TO->dest_effect();
}

void dest_effect(){
    if(objectp(target)){
        if(target->is_player()){
            ::dest_effect();
            if(objectp(TO)) TO->remove();
            return;
        }
    }        
    if(find_call_out("confuse_em")) remove_call_out("confuse_em");
    //added the below check for objectp after environment bugs when the 
    //target had died.  Circe 9/19/05
    if(objectp(mytarg)){
       tell_object(mytarg,"%^MAGENTA%^Suddenly, your mind clears and "+
          "you feel in control again!");
       tell_room(environment(mytarg),"%^MAGENTA%^"+mytarg->QCN+"'s eyes "+
          "suddenly look much more focused.",mytarg);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
