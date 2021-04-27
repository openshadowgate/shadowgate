#include <std.h>
#include <daemons.h>
#include "../lusell.h"
inherit MONSTER;

int FLAG,dlevel,num,timer;
object ob;

create() {
    	::create();
    	set_name("corporal");
    	set_id(({"monster","corporal","guard"}));
    	set_short("corporal");
    	set_long("This is a corporal of the watch.  The guard looks "+
    		"to more seasoned than the privates and has the scars to prove it.");
    	set_body_type("human");
    	dlevel = random(10) +15;
    	set_hd(dlevel,10);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(5);
    	set_race(random(2)?"human":"half-orc");
    	set_gender("male");
    	set_overall_ac(0);
    	set_stats("strength",random(5)+14);
    	set_stats("dexterity",random(5)+14);
    	set_stats("intelligence",random(5)+14);
    	set_stats("wisdom",random(5)+14);
    	set_stats("constitution",random(5)+14);
    	set_stats("charisma",random(5)+14);
   	set_size(2);
   	set_exp(dlevel*50);
    	set_max_hp((random(50)+(dlevel*10)));
    	set_hp(query_max_hp());
    	set_achats(0,({
			"The corporal eyes you cautiously.",
			"The corporal tried to go to your blindside.",
			"The private circles you warily.",
			"The private feints right, feints left then strikes right.",
			"%^BOLD%^%^CYAN%^The corporal screams: %^RESET%^TO ARMS! TO ARMS! INTRUDERS!!.",
    	}),0);
    	set_emotes(0,({
    		"The corporal take in the surroundings.",
    		"The corporal scratches under his chinstrap.",
			"The corporal yawns.",
			"The corporal adjusts his armor.",
			"The corporal clears his throat.",
			"The corporal fidgets with the hilt of it's weapon.",
    	}),0);
    	add_money("copper",random(1000));
    	add_money("silver",random(1000));
  		ob = new( CWEAP+"spear_lg.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",3);
    		command("wield spear");
		ob = new(CARM+"chain.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear chain");
    	command("speak common");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
    	set_property("swarm",1);
		FLAG = 0;
    	set_speed(35);
		set_property("knock unconscious");
		call_out("makeem",0,TO);
}

void init(){
	string mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

	if(mname == "lusell"){
		force_me("emote snaps to attention briskly.");
		return;
	}
	if(TP->query_unconscious())return;	
	if(TP->query_bound())return;
	if(present("emerald clasp",TP)){
		force_me("nod "+mname);
		return;
	}else{
		force_me("yell INTRUDERS!!!");
		TO->kill_ob(TP);
		if (!random(3))force_me("rush "+TP->query_name());
		return;
	}
}
void makeem(object targ){
	ob = new(LMON+"private_nm");
	ob->move(ETO);
	targ->add_follower(ob);
	ob->command("protect corporal");

	ob = new(LMON+"private_nm");
	ob->move(ETO);
	targ->add_follower(ob);
	ob->command("protect corporal");

	if(random(2)){
		ob = new(LMON+"private_nm");
		ob->move(ETO);
		targ->add_follower(ob);
		ob->command("protect corporal");
	}
	if(random(2)){
		ob = new(LMON+"private_nm");
		ob->move(ETO);
		targ->add_follower(ob);
		ob->command("protect corporal");
	}
	if(random(2)){
		ob = new(LMON+"private_nm");
		ob->move(ETO);
		targ->add_follower(ob);
		ob->command("protect corporal");
	}
	if(random(2)){
		ob = new(LMON+"private_nm");
		ob->move(ETO);
		targ->add_follower(ob);
		ob->command("protect corporal");
	}
}
void heart_beat() {
  	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
  	if (FLAG == 0)return;

  	timer++;
   if(timer > 100){
   	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    	if(!present("private"))call_out("makeem",0,TO);
    	return;
   }
}
