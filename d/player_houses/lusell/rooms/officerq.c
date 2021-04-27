//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("officerq");
	set_short("officer's quarters");
	set_long(
		"The room is very ordered and clean.  On the north wall you can "+
		"see the coat of arms of this keep and the badge of office "+
		"which show the station "+
		"of this officer as captain of the guard.  The bed looks a bit more "+
		"comfortable than those you have seen in the barracks and a small "+
		"fireplace dominates the west wall.  Against the east wall is a desk "+
		"and a chair.  A table with a mirror sits near the bed and a ewer and "+
		"basin sit in front of the mirror.  At the foot of the bed is a chest.\n"
	);
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room smells clean with the faint aroma of cologne.");
	set_listen("default","The room is very quiet.");
	set_items(([
		"bed" : "The bed seems very soft and comfortable and smells as if "+
			"slightly perfumed.\n",
		"chest" : "The chest is rectangular, made of wood, and "+
			"will store much of a captain's personal belongings.\n",
		({"chair","desk"}) : "The chair sits before the desk.  The desk "+
			"has writing utensil and paper on top.  Everything seems "+
			"ordered and in its place.\n",
		"table" : "The table is more an elaborate nightstand with a mirror.  "+
			"The ewer is filled with fresh water and the basin sits atop a "+
			"clean, folded towel.\n",
		({"ewer","basin","wash basin"}) : "These devices are used to refresh "+
			"oneself when they awake.  The ewer is always filled with fresh water "+
			"and the basin is clean and dry.  Under the basin is a small towel "+
			"folded neatly.\n",
		({"coat of arms","badge of office"}) : "The coat of arms show the "+
			"unmistakable workings of Kossuth's influence in symbols.  The "+
			"badge of office shows this room to belong to the captain of the guard.\n" 
   ]));
  	set_exits(([
		"south" : LROOMS+"hall5"
	]));

  	set_door("north door",LROOMS+"hall5","south","ruby key");
   set_door_description("north door","A simple wooden door.\n");
   set_string("north door","open","The door opens into a large hallway.\n");
}
