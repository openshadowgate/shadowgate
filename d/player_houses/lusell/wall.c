#include <std.h>
#include "lusell.h"
inherit VAULT;

void create(){
::create();
	set_short("wall walkway");
	set_long(
		"This walkway is along the wall around the "+
		"outside of the keep.  The walkway seems to "+
		"connect to each of the archer towers.\n"
    	);
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","Fresh smells of the outdoors are here "+
		"mixed with the smoke from nearby wood fires.");
	set_listen("default","A bird chirps in the woods below you "+
		"and the occassional creak of leather is heard nearby.");
	set_items(([
		({"walls","wall"}) : "The walls are made of sturdy stone and "+
			"have narrow slits through which archers can fire down on "+
			"the enemy without exposing themselves greatly.\n",
		"floor" : "The floor is clean from all dirt and debris and is made from stone.",
   ]));
}