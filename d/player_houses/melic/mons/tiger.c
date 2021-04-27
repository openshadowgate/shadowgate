inherit "/std/monster";
#include <std.h>
#include <daemons.h>
#include "../melic.h"

void create() {
  	::create();
  	set_name("tiger");
  	set_id(({"tiger","cat"}));
  	set("race","feline");
  	set_gender("male");
  	set("short","%^ORANGE%^tiger%^RESET%^");
  	set("long","%^RESET%^"+
		"The tiger is %^BOLD%^%^YELLOW%^yellow%^RESET%^ with "+
		"%^BOLD%^%^BLACK%^black%^RESET%^ stripes.  By his size and rippling "+
		"sleak muscles it looks like he he could easily take down a horse if "+
		"he was hungry, but at present he lies quietly watching all that "+
		"occurs around him.  Maybe the peacefullness of the garden has tamed "+
		"the savage beast.\n"
	);
  	set_moving(0);
  	set_overall_ac(0);
  	set_level(10);
  	set_body_type("quadruped");
  	set_class("fighter");
  	set("aggressive",2);
  	set_alignment(2);
  	set_size(2);
  	set_hd(5,2);
  	set_stats("strength",18);
  	set_stats("charisma", 6);
  	set_stats("dexterity",18);
  	set_stats("constitution",14);
  	set_stats("wisdom",3);
  	set_stats("intelligence",3);
  	set_hp(200);
  	set_exp(1);
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
  	if(str == "tiger"){
     		tell_object(TP,"You reach out to pet the tiger.  He looks at your hand "+
     			"like it was a snack and you think better of petting a wild tiger!\n");     		tell_room(ETP,""+TPQCN+" reaches out to pet the tiger.  "+TPQCN+" suddenly "+
     			"decides that is not a good idea!\n",TP);
     		return 1;
     	}
}