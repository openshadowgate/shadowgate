#include <std.h>
inherit MONSTER;

void create() {
   object ob1, ob2;
   ::create();
   set_name("ghostly figure");
   set_id(({"figure","ghostly figure"}));
   set_short("%^RESET%^ghostly figure%^BOLD%^%^RED%^");
   set_long("%^BOLD%^%^BLACK%^This creature is made up of nothing but shadows and mist, yet somehow it still seems to have a discernable form. About the size and shape of a man, it has a limber frame that moves with ethereal ease and grace. Darkly gleaming blades rest in either of its hands, a shadowy assassin that settles its eyeless gaze upon you.%^RESET%^");
   set_race("undead");
   set_body_type("human");
   set_gender("neuter");
   set_size(2);
   set_alignment(9);
   set_class("thief");
   set_class("assassin");
   set_level(36);
   set_hd(36,10);
   set_overall_ac(-10);
   set_guild_level("thief",36);
   set_guild_level("assassin",36);
   set_mlevel("thief",36);
   set_mlevel("assassin",36);
   set_max_hp(275);
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_property("swarm",1);
   set_property("no_bump",1);
   set_property("magic",1);
   set_stats("strength",25);
   set_stats("dexterity",23);
   set_stats("constitution",17);
   set_stats("wisdom",7);
   set_stats("intelligence",7);
   set_stats("charisma",3);
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   set_property("assassin",1);
   add_search_path("/cmds/thief");
   add_search_path("/cmds/assassin");
   add_damage_bonus(2+random(9));
   add_attack_bonus(2+random(9));
   set_mob_magic_resistance("average");
   set_new_exp(35,"very high");
   ob1 = new("/d/attaya/obj/screamer");
   ob1->set_property("monsterweapon",1);
   ob1->move(TO);
   command("wield dagger in right hand");
   ob2 = new("/d/attaya/obj/screamer");
   ob2->set_property("monsterweapon",1);
   ob2->move(TO);
   command("wield dagger in left hand");
   set_invis();
   set_funcs(({"fire","kdit"}));
   set_func_chance(15);
   set_scrambling(1);
   set_skill("stealth",40);
   set_skill("athletics",40);
   set_moving(1);
   set_speed (20);
   command("speak wizish");
   command("speech %^BLUE%^hisse");
   set_monster_feats(({
      "ambidexterity",
      "whirl",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "greater two weapon fighting",
	  "two weapon defense",
	  "dodge",
	  "evasion",
	  "mobility",
	  "scramble",
	  "spring attack",
	  "expertise",
	  "knockdown",
	  "unassailable parry",
	  "combat reflexes"
   }));
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void init(){
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
   ::init();
   if(wizardp(TP)) return;
   if(TP->query_true_invis()) return;
   switch(random(3)) {
     case 0: command("say %^CYAN%^come, mortal, and I will drink your life!%^RESET%^"); break;
     case 1: command("say %^CYAN%^we will take this place of life and light and consume it!%^RESET%^"); break;
     default: command("say %^CYAN%^a feast, so many living things!%^RESET%^"); break;
   }
   command("stab "+TPQN);
}

void die(object ob){
   object ob3;
   tell_room(ETO,"%^BOLD%^%^CYAN%^The ghostly figure shrieks and vanishes!%^RESET%^");
   TO->move("/d/shadowgate/void");
   TO->remove();
}

void fire(object targ){
   string dam;
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   tell_object(targ,"%^BOLD%^%^CYAN%^The ghostly figure lunges at you with an otherworldly scream that rings in your ears and staggers you!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^CYAN%^The ghostly figure lunges at "+targ->QCN+" with an otherworldly scream, and "+targ->QS+" staggers back!%^RESET%^",targ);
   set_property("magic",1);
  targ->do_damage("torso",random(100));
  targ->set_paralyzed(random(10)+15,"%^BOLD%^%^CYAN%^The unearthly scream rings in your ears!%^RESET%^");
   remove_property("magic");
   return 1;
}

void kdit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void heart_beat() {
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if((int)TO->query_hp() < 275) TO->add_hp(random(10)+1);
}