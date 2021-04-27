#include <std.h>
#include <daemons.h>
#include "../lusell.h"
inherit MONSTER;

int FLAG,dlevel,num,timer;
object ob;

create() {
    	::create();
    	set_name("private");
    	set_id(({"monster","private","guard"}));
    	set_short("private");
    	set_long("This is a private of the watch.  The guard looks "+
    		"to be very young and has probably never seen battle.");
    	set_body_type("human");
    	dlevel = random(10) +10;
    	set_hd(dlevel,10);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(5);
    	set_race(random(2)?"human":"half-orc");
    	set_gender("male");
    	set_overall_ac(0);
    	set_stats("strength",random(7)+12);
    	set_stats("dexterity",random(7)+12);
    	set_stats("intelligence",random(7)+12);
    	set_stats("wisdom",random(7)+12);
    	set_stats("constitution",random(7)+12);
    	set_stats("charisma",random(7)+12);
   	set_size(2);
   	set_exp(dlevel*50);
    	set_max_hp((random(50)+(dlevel*10)));
    	set_hp(query_max_hp());
    	set_achats(0,({
			"The private fiddles with the hilt of its weapon nervously.",
			"The private lunges at you hesitantly.",
			"The private circles you cautiously.",
			"The private feints right and strikes left.",
			"%^BOLD%^%^CYAN%^The private screams: %^RESET%^TO ARMS! TO ARMS! INTRUDERS!!.",
    	}),0);
    	set_emotes(0,({
    		"The private nervously watches the surroundings.",
    		"The private yawns and scratches under his chinstrap.",
			"The private leans against a wall momentarily.",
			"The private nervously adjusts his armor.",
			"The private coughs quietly.",
			"The private fidgets with the hilt of it's weapon.",
    	}),0);
    	add_money("copper",random(1000));
  		ob = new( CWEAP+"halberd.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",2);
    		command("wield halberd");
		ob = new(CARM+"banded.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear banded");
    	command("speak common");
    	command("speech speak nervously");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
    	set_property("swarm",1);
		FLAG = 0;
    	set_speed(35);
		set_property("knock unconscious");
}

void init(){
	string mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

	if(mname == "lusell"){
		force_me("emote snaps to attention.");
		return;
	}
	if(TP->query_unconscious())return;	
	if(TP->query_bound())return;
	if(present("emerald clasp",TP)){
		return;
	}else{
		TO->kill_ob(TP);
		if (!random(3))force_me("rush "+TP->query_name());
		return;
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
    	return;
   }
}
