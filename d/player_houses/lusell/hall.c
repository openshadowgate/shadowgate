#include <std.h>
#include "lusell.h"
inherit VAULT;

void create(){
::create();
	set_short("hallway");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
		"The hallway is wide and the ceiling is high.  The "+
		"walls are made from granite and spaced at regular "+
		"intervals are sconces with torches ready to light to "+
		"drive away the darkness.  The floor is clean and the "+
		"walls are free of dust and cobwebs.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells clean with barest hint of weapon oil.");
	set_listen("default","An occassional clank of armor can be heard nearby.");
	set_items(([
		({"sconce","sconces"}) : "Metal torch holders with are spaced along "+
			"the walls to provide light.\n",
		({"walls","wall"}) : "The walls are made from granite, but the "+
			"granite slabs have been polished down to remove most of their "+
			"roughness.  The walls are clean and free from dust and cobwebs.\n",
		"floor" : "The floor is clean from all dirt and debris and is made from stone.",
		"ceiling" : "The ceiling hangs approximately twelve feet over "+
			"your head and look to be clean as the rest of the hall.  Even "+
			"above the torches where you would expect to find soot, there "+
			"is no dirty residue apparent.\n"
   ]));
}