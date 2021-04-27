#include <std.h>

inherit MONSTER;

#define ALLIES ({ "saradin", "stefano", "lusell", "lliira", "vincent", "saradin", "morar", "ymodos", "mythrias", "burly pirate" , "raelith" , "shrydelhi"})

void create(){
	object ob;
   	::create();
    	set_name("burly pirate");
    	set_short("burly pirate");
    	set_id( ({"pirate", "burly pirate"}) );
    	set_long("%^RESET%^%^ORANGE%^"+
    		"This is a burly and rough looking pirate that clearly hasn't bothered "
		"to shave in several days.  His heavily muscled arms have numerous "
		"scars, probably from having seen his share of battles.  He's clad in "
		"heavy leather armor including leggings and boots that look like they "
		"would leave his movement reasonably unhindered but protect very well.\n"
  	);
	set_race("human");
  	set_body_type("human");
    	set_overall_ac(-10);
    	set_hd(35, 10);
    	set_gender("male");
    	set_size(2);
    	ob = new("/d/common/obj/weapon/scimitar");
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
   		ob->set_property("monsterweapon",1);
		command("wield scimitar");
  	ob = new("/d/common/obj/weapon/shortsword");
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
		if(random(3))
	 	   ob->set_property("monsterweapon",1);
		command("wield sword");
     	set_property("swarm",1);
     	set_max_hp(350);
    	set_hp(query_max_hp());
    	set_mob_magic_resistance("average");
	set_property("magic",1);
	set_property("no stab",1);
 	set_property("no hold",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
     	set_exp(2500);
      set_property("full attacks",1);
}

void init() {
    ::init();
    if(TP->query_true_invis()) return;
    if( member_array(TPQN, ALLIES) == -1) {
	if(TP->query_invis())
	   force_me("say I smell and hear ye ya sneaky intruder!");
	else force_me("emote takes one look at "+TPQCN+" and attacks!\n");
       force_me("kill "+TPQN);
    }
}

