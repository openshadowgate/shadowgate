#include <std.h>
#include <daemons.h>
#include "../lusell.h"
inherit MONSTER;

int FLAG,dlevel,num,num2,timer;
object ob;

create() {
    	::create();
    	set_name("sergeant");
    	set_id(({"monster","sergeant","guard"}));
    	set_short("sergeant");
    	set_long("This is a seasoned warrior and because of his "+
    		"skill he has been given the promotion to sergeant.  "+
    		"The way he moves and his scars show that he is the "+
    		"veteran of battle and has survived to fight another day.");
    	set_body_type("human");
    	dlevel = random(10) +20;
    	set_hd(dlevel,10);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(5);
    	set_race(random(2)?"human":"half-orc");
    	set_gender("male");
    	set_overall_ac(0);
    	set_stats("strength",random(3)+16);
    	set_stats("dexterity",random(3)+16);
    	set_stats("intelligence",random(5)+14);
    	set_stats("wisdom",random(5)+14);
    	set_stats("constitution",random(3)+16);
    	set_stats("charisma",random(5)+14);
   	set_size(2);
   	set_exp(dlevel*50);
    	set_max_hp((random(50)+(dlevel*10)));
    	set_hp(query_max_hp());
    	set_achats(0,({
			"The sergeant rushes you.",
			"The sergeant slips around to your right and almost skewers you.",
			"The sergeant slams the flat of his blade against your head.",
			"The sergeant feints with his head and comes at you straight on.",
			"%^BOLD%^%^CYAN%^The sergeant barks: %^RESET%^TO ARMS! TO ARMS! INTRUDERS!!.",
    	}),0);
    	set_emotes(0,({
    		"The sergeant adjusts his armor.",
    		"The sergeant coughs and scratches while watching you.",
			"The sergeant fingers the hilt of his sword expectantly.",
			"The sergeant looks you over closely.",
			"The sergeant watches the area expertly.",
    	}),0);
    	add_money("copper",random(500));
    	add_money("silver",random(500));
    	add_money("gold",random(500));
  		ob = new( CWEAP+"longsword.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
    		command("wield sword");
		ob = new(CARM+"field.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear plate");
      ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(random(25)+20);
    	command("speak common");
    	command("speech bark");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(25);
    	set_property("swarm",1);
		FLAG = 0;
		num2 = 0;
	set_funcs(({"summon"}));
	set_func_chance(25);
		set_property("knock unconscious");
}

void init(){
	string mrace=TP->query_race(),mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

	if(mname == "lusell"){
		force_me("emote snaps to attention briskly.");
		force_me("emote salutes the lady of the keep");
		return;
	}
	if(TP->query_unconscious())return;	
	if(TP->query_bound())return;
	if(present("emerald clasp",TP)){
		return;
	}else{
		switch(random(3)){
			case (0):
				force_me("yell INTRUDERS!!!");
				break;
			case (1):
				force_me("yell TO ARMS!  TO ARMS!!");
				break;
			case (2):
				break;
		}			
		TO->kill_ob(TP);
		if (!random(3))force_me("rush "+TP->query_name());
		return;
	}
}
void summon(object targ){
	string who;

	switch(num2){
		case(0) :
  			command("say WARE! WARE! INTRUDERS!");
  			tell_room(TO,"Guards rush to the sergeant's call.");

			ob = new(LMON+"private_nm");
			ob->move(ETO);
			ob->command("protect sergeant");
			ob->kill_ob(targ);

			ob = new(LMON+"private_nm");
			ob->move(ETO);
			ob->command("protect sergeant");
			ob->kill_ob(targ);

			if(random(2)){
				ob = new(LMON+"private_nm");
				ob->move(ETO);
				ob->command("protect sergeant");
				ob->kill_ob(targ);
			}
			if(random(2)){
				ob = new(LMON+"private_nm");
				ob->move(ETO);
				ob->command("protect sergeant");
				ob->kill_ob(targ);
			}
			num2 = 1;
			return;
		case(1) :
			if(objectp(targ) && present(targ,environment(TO))){
				who = targ->query_name();
				TO->force_me("flash "+who);
			}
			return;
	}

}
void heart_beat() {
  	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;

   if(present("kit",TO) && query_hp() < query_max_hp()/3){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   }
   if(present("bottle",TO)) command("offer bottle");

  	if (FLAG == 0)return;

  	timer++;
   if(timer > 100){
   	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    	return;
   }
}
