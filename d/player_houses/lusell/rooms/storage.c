//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("storeroom");
	set_short("storeroom");
	set_long(
    	"%^BOLD%^%^BLACK%^"+
		"This room is wall to wall shelves with barrels in "+
		"the center.  Against the west wall there are large "+
		"bags resting up against the wall.\n"+ 
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room smells dusty.");
	set_listen("default","The room is very quiet.");
	set_items(([
		({"shelf","shelves"}) : "The shelves are completely stocked "+
			"with all manner of goods necessary to feed a garrison of "+
			"guards during a seige.  There is enough here to keep the "+
			"keep running, if rationed, for several weeks.\n",
		({"barrels","barrel"}) : "The barrels contain may different items "+
			"from nails in one, to ale in another.\n",
		({"sack","sacks"}) : "The sacks contain various items from cornmeal to flour.\n"
   ]));
  	set_exits(([
		"east" : LROOMS+"hall4"
	]));

  	set_door("door",LROOMS+"hall4","east","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens into a large hallway.\n");
}
