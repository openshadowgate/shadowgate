#include <std.h>
#include <daemons.h>
#include "../melic.h"
inherit MONSTER;

void create() {
  	::create();
  	set_name("dog");
  	set_id(({"dog","guard dog"}));
  	set("race","canine");
  	set_gender("male");
  	set("short","%^RESET%^%^ORANGE%^guard dog%^RESET%^");
  	set("long","%^RESET%^"+
		"This dog looks alot like a wolf, but it's somewhat heavier and in "+
		"better condition than the average wild %^ORANGE%^wolf%^RESET%^ would "+
		"be.  It has been trained as a guard dog and now serves as one at this "+
		"castle.  The animal lies obediently at the feet of the old guard.\n");
  	set_moving(0);
  	set_overall_ac(0);
  	set_level(10);
  	set_body_type("quadruped");
  	set_class("fighter");
  	set("aggressive",2);
  	set_alignment(2);
  	set_size(1);
  	set_hd(5,2);
  	set_stats("strength",16);
  	set_stats("charisma", 6);
  	set_stats("dexterity",16);
  	set_stats("constitution",14);
  	set_stats("wisdom",3);
  	set_stats("intelligence",3);
  	set_hp(75);
  	set_exp(01);
    	set_emotes(5,({
    		"Dog wags his tail.",
    		"Dog licks himself thoroughly.",
		"Dog bites at fleas on his back leg.",
		"Dog sniffs at the old half-elfs hand.",
		"Dog curls up at the old half-elf feet and goes to sleep."
    	}),0);
}
void init() {
  	::init();
  	add_action("pet","pet");
}
int pet(string str) {
    	if(!str) {
        	tell_object(TP,"Pet what?");
        	return 1;
    	}
  	if(str == "dog"){
     		tell_object(TP,"You pet the dog.  He licks your hand and wags his tail!\n");
     		tell_room(ETP,""+TPQCN+" pets the dog.  The dog licks "+TPQCN+" and wags his "+
			"tail!\n",TP);
     	return 1;
     	}
}