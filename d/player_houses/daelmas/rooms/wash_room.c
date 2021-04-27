//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Wash room");
   set_short("wash room");
   set_long(
   	"%^RESET%^"+
   	"A large circular shaped bath sits in the middle of this "+
   	"beautifully decorated room.  The bath is carved of "+
   	"%^BOLD%^%^CYAN%^pale blue marble%^RESET%^, and sits above the "+
   	"rest of the room, with three steps leading up to the area. "+
   	"Above the bath, the %^BOLD%^%^CYAN%^blue marble%^RESET%^ creates "+
   	"a dome shape, and is supported by %^BOLD%^%^BLUE%^thin "+
   	"blue pillars%^RESET%^, which are lightly covered with ivy "+
   	"and sit back against the walls. Behind the tub are "+
   	"many %^BOLD%^white candles %^RESET%^that seem to illuminate "+
   	"the entire room. Below you, the floor is an intricate pattern "+
   	"of lightly colored %^BOLD%^%^BLUE%^blue%^RESET%^ and "+
   	"%^BOLD%^%^MAGENTA%^violet %^RESET%^stones. A small "+
   	"fireplace along the south wall provides"+
   	" heat to the room and above it, a shelf holds various bottles "+
   	"of oils and soaps, along with %^BOLD%^%^BLUE%^thick blue "+
   	"towels%^RESET%^.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The fresh scent of lavender and spice invigorates you.");
   set_listen("default","The room is silent and peaceful.");
   set_items(([
		"bath" : "The bath is carved of pale blue marble, and is quite "+
			"large and deep.  A golden faucet hangs over the side of "+
			"the tub, with two golden knobs.  One is, apparently, for "+
			"hot water and the other for cold.\n",
		"ceiling" : "The ceiling above your head is dome shaped and a "+
			"shade darker than the rest of the pale blue room.\n",
		"floor" : "Blue and violet stones circle the bath, and are slightly "+
			"warm to the touch.\n",
		"fireplace" : "The small fireplace provides ample heat for the "+
			"entire room.",
		"shelf" : "Towels and oils line the shelf, giving off a wonderful "+
			"aroma.\n"
	]));

   set_door("eastern door",DROOMS+"land2","west","marble key");
   set_door_description("eastern door","The door is polished and made from oak.");
   set_string("eastern door","open","You open the door onto the second landing.\n");

   set_exits(([
		"west" : DROOMS+"land2"
   ]));
}
void init() {
  	::init();
  	add_action("light","light");
}
int light(string str) {
   if(!str) {
     	tell_object(TP,"Light what?");
     	return 1;
   }
  	if(str == "fire" || str == "a fire" || str == "the fire"){
     	tell_object(TP,"%^BOLD%^%^YELLOW%^You throw a few logs into the "+
     		"fireplace and soon you have a bright fire burning.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" tosses a few logs into "+
        	"the fire and soon has a bright fire blazing.\n%^RESET%^",TP);
		return 1;
   }
}