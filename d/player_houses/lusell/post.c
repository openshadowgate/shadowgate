#include <std.h>
#include "lusell.h"
inherit VAULT;

void create(){
::create();
	set_short("guard post");
	set_long(
    	"%^RESET%^%^CYAN%^"+
		"This small room has a table and a couple of chairs.  "+
		"This is where guards return to when the watch changes, in "+
		"the meantime they can be found here or walking their posts.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells clean with barest hint of weapon oil.");
	set_listen("default","An occassional clank of armor can be heard nearby.");
	set_items(([
		({"walls","wall"}) : "The walls are made from granite, but the "+
			"granite slabs have been polished down to remove most of their "+
			"roughness.  The walls are clean and free from dust and cobwebs.\n",
		"floor" : "The floor is clean from all dirt and debris and is made from stone.",
		"ceiling" : "The ceiling hangs approximately twelve feet over "+
			"your head and look to be clean as the rest of the hall.  Even "+
			"above the torches where you would expect to find soot, there "+
			"is no dirty residue apparent.\n",
		({"table","chair","chairs"}) : "Simple and wooden the table and "+
			"chairs are here to provide the guards a place to sit, but "+
			"comfort was not the aim.\n"
   ]));
}