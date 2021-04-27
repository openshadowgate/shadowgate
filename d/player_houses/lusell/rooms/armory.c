//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("armory");
	set_short("armory");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
		"This small room hold weapons and armor for the guards "+
		"and other dummy equipment for use in the drills.  Nothing "+
		"of real value remains here that could not be purchased for "+
		"a song in the nearest town.  Used armor of all types save "+
		"leather and studded rest against the north wall.  Racks of "+
		"swords, spears, and lances fill the east wall.  Nothing you "+
		"find in this room would be fit for a knight, but would serve "+
		"the guards well.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells of weapon oil and steel.");
	set_listen("default","An occassional clank of armor can be heard nearby.");
	set_items(([
		({"rack","racks"}) : "Several racks along the east wall hold "+
			"servicable, but very used weapons.  One rack holds spears, "+
			"another swords, and yet another holds lances.\n",
		({"armor","armors"}) : "The armor here is in good condition and "+
			"has seen its share of usage.  Mostly what you see here is what "+
			"a guard will use in order not to damage his regular equipment.  "+
			"There is no armor of leather in this building, nothing a knight "+
			"might consider the gear of the lowly thief.\n"
   ]));
  	set_exits(([
		"south" : LROOMS+"drill_yard"
	]));

  	set_door("door",LROOMS+"drill_yard","south","ruby key");
   set_door_description("door","This is a simple wooden door.\n");
   set_string("door","open","The doors open to a large grass and dirt practice yard.\n");
}
