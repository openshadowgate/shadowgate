//guardian.c - The invisible guardians for Stefano's house.  Coded by Circe 11/3/03
#include <std.h>
inherit MONSTER;

#define POWNERS ({ "gaius" }) //controls access to most secure parts of the house
#define PGUESTS ({ "nymeria", "testlackey" }) //controls access to the house in general

int lvl = random(10)+25;
void create(){
   object ob,ob2;
   ::create();
  set_name("unseen guardian");
   set_short("Unseen Guardian");
   set_id(({"guardian","unseen guardian","Unseen Guardian","Guardian"}));
   set_alignment(6);
   set_class("thief");
   set_class("fighter");
   set_race("human");
   set_hd(random(30)+20,8);
   set_max_hp(random(150)+250);
   set_hp(query_max_hp());
   set_exp(2000);
   set_gender("male");
   set_long("This rugged looking man has several long scars running the "+
      "length of his face.  His is thin, but well-muscled, and he has a "+
      "determined, evil gleam in his pale eyes.  Shadows seem to coalesce "+
      "around him, making him somewhat difficult to spot.  He is dressed in "+
      "simple leathers and moves with a soundless, cat-like grace.  He wears "+
      "no armor, but two wickedly curved daggers are strapped to his thighs."
   );
   set_guild_level("thief",lvl);
   set_guild_level("fighter",lvl);
   set_mlevel("thief",lvl);
   set_mlevel("fighter",lvl);
   ob = new("/d/attaya/obj/screamer");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wield dagger");
   set_overall_ac(0);
   ob = new("/d/deku/armours/ring_p");
   ob->set_property("monsterweapon",1);
   ob->set_property("enchantment",4);
   ob->move(TO);
   force_me("wear ring");
   ob = new("/d/common/obj/potion/legendary_heal");
   ob->move(TO);
   ob->set_uses(random(25)+25);
   ob = new("/d/tharis/obj/wrist_sheath");
   ob->set_property("monsterweapon",1);
   ob2 = new("/d/attaya/obj/screamer");
   ob2->set_property("monsterweapon",1);
   ob2->set_size(1);
   ob2->move(TO);
   ob2->move(ob);
   ob->move(TO);
   force_me("wear sheath");
   set_property("full attacks",1);
   set_money("gold",random(3000));
   set_mob_magic_resistance("average");
   set_property("aggressive",6);
   set_property("swarm",1);
   add_search_path("/cmds/thief");
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   set_scrambling(1);
   set_invis();
   set_stats("strength",19);
   set_stats("dexterity",random(3)+16);
   set_stats("intelligence",random(5)+14);
   set_stats("wisdom",random(5)+14);
   set_stats("constitution",random(3)+16);
   set_stats("charisma",random(5)+14);
}

void init(){
	string mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

//	if(mname == "stefano"){

   if(member_array(mname,POWNERS) != -1){
		force_me("protect "+mname+"");
		return;
	}
	if(TP->query_unconscious())return;	
	if(TP->query_bound())return;
	if(present("rune_key",TP) || member_array(mname,PGUESTS) != -1){
		return;
	}else{
		force_me("say You do not belong here!");
            force_me("stab "+TPQN+"");
		return;
	}
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp()< 80 && present("vial",TO)){
    	force_me("open vial");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
    	force_me("quaff vial"); 
    	force_me("offer bottle");
    	force_me("quaff vial");    
    	force_me("offer bottle");
    	force_me("quaff vial");
    	force_me("offer bottle");
	}
}
