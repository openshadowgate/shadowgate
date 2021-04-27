#include <std.h>
#include "/d/player_houses/kiya/defs.h"
inherit WEAPONLESS;

object *pplzglobal = ({});
int echoflag;

create() {
   ::create();
   set_name("dryad");
   set_id(({ "dryad","nymph","tree spirit"}));
   set_short("%^RESET%^%^GREEN%^a graceful dryad%^RED%^%^BOLD%^");
   set_long("%^CYAN%^This ethereal creature is very hard to keep in vision, as she seems almost part of "
"the %^GREEN%^for%^ORANGE%^e%^GREEN%^st%^CYAN%^ around her.  The easiest feature to concentrate on are "
"her eyes, which are of a striking %^MAGENTA%^violet%^CYAN%^ hue and glimmer with intelligence.  She has "
"a lithe figure, with slender fingers and flawlessly smooth, %^ORANGE%^tanned%^CYAN%^ skin of the same "
"hue as the trees around her.  %^GREEN%^Soft g%^BOLD%^r%^RESET%^%^GREEN%^een hair%^CYAN%^ surrounds her "
"delicately-featured face, interpersed with a multitude of "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^, and her ears are pointed like "
"those of an elf.  Loose clothing wreathes her figure, blending perfectly with her surroundings in "
"countless shades of %^ORANGE%^brown%^CYAN%^ and %^GREEN%^green%^CYAN%^.%^RESET%^");
   set_hd(10,10);
   set_alignment(5);
   set_race("dryad");
   set_gender("female");
   set_body_type("human");
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set("aggressive","agg_fun");
   set_stats("intelligence",16);
   set_stats("wisdom",15);
   set_stats("strength",19);
   set_stats("charisma",20);
   set_stats("dexterity",19);
   set_stats("constitution",17);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no death",1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no dominate", 1);
   set_property("no web", 1);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no bows",1);
   set_property("knock unconscious",1);
   set_property("magic",1);
   set_size(2);
   set_exp(0);
   set_overall_ac(-15);
   set_max_hp(800);
   set_hp(query_max_hp());
   set_damage(4,8);
   set_attack_limbs( ({"right hand","left hand"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_achats(2, ({"%^CYAN%^The dryad's %^MAGENTA%^violet%^CYAN%^ eyes flash with rage.",
"%^CYAN%^The dryad moves in and out of view amongst the trees.",
"%^CYAN%^The dryad murmurs a string of words you can't understand."}) );
   set_invis(1);
}

void init() {
    ::init();
    add_action("deflect_fun","stab");
    add_action("deflect_fun","crit");
}

void agg_fun() {
   heart_beat();
}

int is_summoned(object ob) {
   if(ob->id("summoned monster") || ob->id("undead")) return 1;
   else return 0;
}

int is_target(object obj) {
    if(obj->query_true_invis()) return 0;
    if(obj->is_player()) return 1;
    else return 0;
}

void heart_beat() {   
    object *pplz = ({}),*mobs = ({});
    int i;
   
    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if(TO->query_hp()<800) TP->add_hp(random(10)+5);

    if(TO->query_tripped()) {
      tell_room(ETO,"%^CYAN%^The dryad shakes off the dazing effect.");
      TO->set_tripped(0);
    }
    if(TO->query_paralyzed()) {
      tell_room(ETO,"%^CYAN%^The dryad shakes off the dazing effect.");
      TO->set_paralyzed(0);
    }
    
    if (sizeof(all_inventory(ETO))) {
      mobs = filter_array(all_inventory(ETO),"is_summoned",TO);
      if (sizeof(mobs)) {
        if (TO->query_invis()) tell_room(ETO,"%^GREEN%^The air around you shimmers, and the summoned "
"creatures vanish!%^RESET%^"); 
        else tell_room(ETO,"%^GREEN%^The dryad waves her arms, as the air around you shimmers and the "
"summoned creatures vanish!%^RESET%^"); 
        for(i=0;i<sizeof(mobs);i++) {
          TO->remove_attacker(mobs[i]);
          mobs[i]->move("/d/shadowgate/void");
          mobs[i]->remove();
        }
      }
    }
   
    if(sizeof(TO->query_attackers())) {
      if (TO->query_invis()) {
        TO->set_invis(0);
        tell_room(ETO,"%^GREEN%^The dryad shrieks in an unearthly tone and raises up to defend her "
"forest!\n");
      }        
      if (echoflag == 0) {
        echoflag = 50;
        tell_room(ROOMS+"house1","%^ORANGE%^An almost imperceptable shiver runs up through the tree.");
        tell_room(ROOMS+"house2","%^ORANGE%^An almost imperceptable shiver runs up through the tree.");
        tell_room(ROOMS+"house3","%^ORANGE%^An almost imperceptable shiver runs up through the tree.");
        tell_room(ROOMS+"bridge","%^ORANGE%^An almost imperceptable shiver runs up through the tree.");
      }

      pplz = filter_array(TO->query_attackers(),"is_target",TO);
      if(!sizeof(pplzglobal)) { pplzglobal = pplz; }
      if(sizeof(pplz)) {
        for(i=0;i<sizeof(pplz);i++) {
          if(!(member_array(pplz[i],pplzglobal) + 1) ) pplzglobal += pplz[i];
        }
      }
    }
     
    if(!TO->query_invis() && !sizeof(TO->query_attackers())) {
        TO->set_invis(1);      
        echoflag = 0;
        TO->set_funcs(({}));
        TO->set_func_chance(0);
        if(query_hp() < query_max_hp()) set_hp(query_max_hp());
    }   

    if(sizeof(pplzglobal)) {
      for (i=0;i<sizeof(pplzglobal);i++) {
        if(pplzglobal[i]->query_unconscious()) {
          tell_room(ETO,"%^GREEN%^The dryad motions with one slender arm.\n\nThe wind picks up around "
+pplzglobal[i]->QCN+", scattering leaves around and lifting "+pplzglobal[i]->QO+" from the ground.\n\nA "
"glitter of magical energy appears around "+pplzglobal[i]->QCN+", who suddenly "
"vanishes!%^RESET%^\n",pplzglobal[i]);
          tell_object(pplzglobal[i],"%^CYAN%^A strange sensation fills your body, and then is gone as "
"suddenly as it came.%^RESET%^\n");
          pplzglobal[i]->move(ROOMS+"path1");
          tell_room(ROOMS+"path1","%^ORANGE%^The air shimmers with magical energy, as "+pplzglobal[i]->QCN+
" suddenly appears and drops lightly upon the ground!%^RESET%^",pplzglobal[i]);
          pplzglobal -= ({pplzglobal[i]});
        }
      }
    }
    if(echoflag > 0) echoflag = echoflag -1;
    //moved here to fix an error with the player not getting teleported if KO'd before the first heartbeat
    if(!sizeof(TO->query_funcs())) {
      TO->set_funcs(({"vines","pollen","pollen","mindcontrol","mindcontrol","drain","slashem"}));
      TO->set_func_chance(60);
    }
    return;
}

void vines(object target) {
   tell_room(ETO,"%^GREEN%^The dryad spreads her slender arms, calling upon the forest to aid her!");
   tell_room(ETO,"%^GREEN%^The vines on the trees around you come to life, wrapping around "+target->QCN+
" and holding "+target->QO+" still!",target);
   tell_object(target,"%^GREEN%^The vines on the trees around you come to life, entwining around you so "
"you can't move!");
   target->set_paralyzed(25,"The vines won't let you free!");
}

void pollen(object target) {
   object *pplz;
   int i;
   pplz = query_attackers();
   tell_room(ETO,"%^GREEN%^The dryad motions gently to the flowers hanging from the vines nearby.\nThe "
"flowers open their petals, sending a soft rain of pollen down over you.");
   for(i=0;i<sizeof(pplz);i++) {
     if("daemon/saving_d"->saving_throw(pplz[i],"paralyzation_poison_death")) {
       tell_room(ETO,"%^GREEN%^"+target->QCN+" screams as a little of the pollen touches "+target->QP+
" eyes!",target);
       tell_object(target,"%^GREEN%^A little of the pollen touches your eyes, burning painfully!");
       target->set_temporary_blinded(5,"Your eyes are still burning from the pollen!");
     }
     else {
       tell_room(ETO,"%^GREEN%^The pollen falls down around "+target->QCN+", who takes on a drowsy look "
"and suddenly falls upon the ground, asleep!",target);
       tell_object(target,"%^GREEN%^The pollen falls down around you, and you find yourself becoming very "
"drowsy!");
       target->set_unconscious(random(10)+40);
     }
   }
}

void mindcontrol(object target) {
   tell_room(ETO,"%^GREEN%^The dryad extends both arms forward, focussing her gaze upon "
+target->QCN+".",target);
   tell_object(target,"%^GREEN%^The dryad extends both arms forward, focussing her gaze upon you.\nYou "
"feel a prescence touch at your mind!");
   if(random(15)+11 > target->query_stats("wisdom")) {
     if(target->query_paralyzed()) { target->set_paralyzed(0); }
     tell_room(ETO,"%^GREEN%^"+target->QCN+" takes on a trance-like look and simply walks away.",target);
     tell_object(target,"%^GREEN%^The presence bids you to walk away, and you turn and step north into "
"the forest.");
     TO->remove_attacker(target);
     target->remove_attacker(TO);
     if(random(2)) { target->force_me("northeast"); }
     else { target->force_me("northwest"); }
//     target->set_paralyzed(25,"You can't will your legs to move!");
   }
   else {
     tell_object(target,"%^GREEN%^You push aside the force pressing at your mind.");
     tell_room(ETO,"%^GREEN%^"+target->QCN+" shakes "+target->QP+" head to clear it.",target);
   }
}

void drain(object target) {
   int dam;
   dam = roll_dice(10,5);
   tell_room(ETO,"%^GREEN%^The dryad spreads her hands, reaching out at "+target->QCN+".",target);
   tell_object(target,"%^GREEN%^The dryad spreads her hands, reaching out at you!");
   if(random(20)+10 > target->query_stats("dexterity")) {
     tell_room(ETO,"%^GREEN%^The dryad presses both hands against "+target->QCN+"'s face.",target);
     tell_object(target,"%^GREEN%^The dryad presses both hands against your face, and you feel the life "
"drain from your body!");
     TO->set_property("magic",1);
     target->do_damage("head",dam);
     TO->do_damage("head",(-1)*dam);
     TO->remove_property("magic");
     switch(random(4)) {
       case 0:
       target->add_stat_bonus("dexterity",-1);
       break;
       case 1:
       target->add_stat_bonus("strength",-1);
       break;
       case 2:
       target->add_stat_bonus("intelligence",-1);
       break;
       case 3:
       target->add_stat_bonus("wisdom",-1);
       break;
     }
   }
   else {
     tell_room(ETO,"%^GREEN%^"+target->QCN+" manages to evade the dryad's touch.",target);
     tell_object(target,"%^GREEN%^You manage to evade the dryad's touch!");
   }
}

void slashem(object target) {
   tell_room(ETO,"%^GREEN%^The dryad screams in fury, slashing wildly at anything within range!");
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
}

int deflect_fun(string str) {
   if (strsrch(str,"dryad") != -1 || strsrch(str,"nymph") != -1 || strsrch(str,"tree spirit") != -1) {
     tell_room(ETO,"%^CYAN%^The dryad seems almost to sense "+TP->QCN+"'s attack before it even comes, "
"evading it with ease, and turning upon "+TP->QO+" in a rage!",TP);
     tell_object(TP,"%^CYAN%^The dryad seems almost to sense your attack before it even comes, evading it "
"with ease, and turning upon you in a rage!");
     force_me("kill "+TP->query_name());
     return 1;
   }
   return 0;
}
