//adapted from Stefano's guards that Circe did *Styx* 5/21/06

#include <std.h>
inherit MONSTER;

void create(){
   int lvl = random(10)+25;
   object ob,ob2;
   ::create();
   set_name("servant");
   set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^len%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ Serv%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^nt of D%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkness%^RESET%^");
   set_id(({"silent servant","servant","darkness", "guard", "silent servant of darkness"}));
   set_alignment(6);
   set_class("thief");
   set_class("fighter");
   set_race("half-elf");
   set_hd(random(20)+20,8);
   set_max_hp(random(100)+250);
   set_hp(query_max_hp());
   set_exp(1000);
   set_gender("male");
   set_long("%^RESET%^%^BOLD%^%^BLACK%^This humanoid being is completely "
"draped in in%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ric%^RESET%^"
"%^MAGENTA%^a%^BOLD%^%^BLACK%^te r%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^"
"bes made of black velvet and etched with %^RESET%^%^MAGENTA%^arc%^BOLD%^"
"a%^RESET%^%^MAGENTA%^ne v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e"
"%^RESET%^%^MAGENTA%^t r%^BOLD%^u%^RESET%^%^MAGENTA%^nes%^BOLD%^%^BLACK%^."
"  The robes are long and flowing, looking as though they were made for "
"human nobility from centuries past. The being floats above the ground, "
"making no noise and drawing no breath. Within the hood drawn low over its "
"head is pure darkness that gives off an unnatural feeling of %^RESET%^"
"%^RED%^m%^BOLD%^a%^RESET%^%^RED%^lev%^BOLD%^o%^RESET%^%^RED%^lence"
"%^BOLD%^%^BLACK%^.%^RESET%^"
   );
   set_guild_level("thief",lvl);
   set_guild_level("fighter",lvl);
   set_mlevel("thief",lvl);
   set_mlevel("fighter",lvl);
   ob = new("/d/attaya/obj/screamer");
     ob->set_property("monsterweapon",1);
     ob->move(TO);
     force_me("wield dagger");
   set_overall_ac(-20);
   ob = new("/d/common/obj/potion/healing");
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
   set_mob_magic_resistance("average");
   set_property("aggressive",6);
   set_property("swarm",1);
   add_search_path("/cmds/thief");
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   set_scrambling(1);
   set_stats("strength",19);
   set_stats("dexterity",random(3)+16);
   set_stats("intelligence",random(5)+14);
   set_stats("wisdom",random(5)+14);
   set_stats("constitution",random(3)+16);
   set_stats("charisma",random(5)+14);
}

void init() {
   ::init();
   if((string)TP->query_name() == "rubicant") {
	force_me("protect rubicant");
	return;
   }
/*
   if(TP->query_unconscious())  
	return;	
   if(TP->query_bound())  
	return;
   force_me("say You do obviously do not belong here!");
   force_me("stab "+TPQN+"");
   return;
*/
}

void heart_beat(){
  	::heart_beat();

  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp()< 80 && present("vial",TO)){
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial");
    	force_me("quaff vial"); 
    	force_me("quaff vial");    
    	force_me("quaff vial");
	}
}
