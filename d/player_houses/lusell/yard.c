#include <std.h>
#include "lusell.h"
inherit VAULT;

void create(){
::create();
	set_short("courtyard");
	set_long(
		"The courtyard is paved in cobblestone and is very large.  "+
		"To the north you see the entry to the keep, the west a "+
           "stable and to the east a practice yard.  To the south you "+
		"see the portcullis that leads over the drawbridge and back to Tonovi.\n"
    	);
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","Fresh smells of the outdoors are here "+
		"mixed with the smell of the stables.");
	set_listen("default","You can hear horses stir in the stables "+
		"and the sounds of guards moving about.");
	set_items(([
		({"walls","wall"}) : "The walls are made of sturdy stone and "+
			"have narrow slits through which archers can fire down on "+
			"the enemy without exposing themselves greatly.\n",
		"floor" : "The floor cobblestone and is kept free of dirt and "+
			"debris even though you know the horses are working toward "+
			"the other aim.\n",
   ]));
}
