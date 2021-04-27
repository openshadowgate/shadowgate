#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit WEAPONLESS;

void create(){
    object ob;
   ::create();

   set_name("shadow");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   set_gender("neuter");
   set_property("full attacks",1);
   set("aggressive","sicem");
   set_race("shadow");
      set_short("%^RESET%^%^CYAN%^drifting shadow");
      set_id(({"shadow","drifting shadow"}));
      set_long("This creature is hard even to see, let alone discern its nature. Vaguely humanoid, it has ember-bright eyes that gleam with malign intent. It carries a shadowy blade, which seems almost an extension of its arm.");
       set_hd(31+random(10),9);
      ob = new("/d/shadow/obj/weapon/bastard");
      ob->set_property("monsterweapon",1);
     ob->set_property("enchantment",5);
     ob->move(TO);
     ob->set_name("shadowy blade");
     ob->set_short("shadowy blade");
    command("wield sword");
   add_money("gold",random(500));
    add_money("platinum",random(50));
      set_damage_bonus(8);
      set_overall_ac(-10);
      set_monster_feats(({ "rush" }));
       set_func_chance(35);
       set_funcs(({"rushit"}));
       set_resistance("negative energy",10);

   set_new_exp(35,"very high");
   set_hp(20*query_hd());
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   set_damage(2,10);
   //upped from 3
   set_attacks_num(5);
   set_attack_limbs(({"mouth","right claw","left claw"}));
   set_funcs(({"fire"}));
   set_func_chance(30);
    set_stats("strength",25);
}

void fire(object targ){
   if(!objectp(targ)) return;

   tell_room(ETO,"%^BOLD%^%^BLACK%^The shadowy creature lashes out suddenly at "+targ->query_cap_name()+".", targ);
   tell_object(targ,"%^RED%^The shadowy creature lashes out suddenly at you!");
   set_property("magic",1);
   targ->do_damage("torso",random(75));
   remove_property("magic");
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void sicem()
{
    command("kill "+TP->query_true_name());
    set("aggressive",100);
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^%^CYAN%^The shadow shimmers and disappears!%^RESET%^");
   TO->move("/d/shadowgate/void");
   TO->remove();
}