//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Kitchen");
    set_long(
    	"This large, cozy, spacious kitchen has plenty of room for working.  There is an "+
    	"island in the middle of the room with a workspace on one end and stools around the "+
	"other.  The floor appears to be made of clay tiles and is scrubbed free of dirt and "+
	"grease.  A large iron stove sits in the northwest corner of the room.  In the "+
	"southwest corner is a pantry.  There are pots, pans, and other cooking utensils "+
	"hanging over the work end of the island.  The walls have sconces with candles to "+
	"provide lighting for the room.  There is a door in the south wall leading into "+
	"the dining room.\n"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Hints of wood smoke from the stove mingle with the delicious "+
    			"smells of cooking food.");
    set_listen("default","Bubbling sounds from the pots of boiling food dominate the room.");
    set_items(([
        "island" : "\n%^RESET%^This is a table that appears to be a little over waist high "+
		"on a normal sized human.  The table is fixed to the floor and cannot be "+
		"moved.  The south end has stools set around it and the north end has a work "+
		"area consisting of a cutting block, food preparation area, and utensils "+
		"hanging from above for easy access.\n",
        "stove" : "\n%^RESET%^This is a large, %^BOLD%^%^BLACK%^black%^RESET%^, cast "+
        	"iron stove.  %^ORANGE%^Wood %^RESET%^can be placed into the lower front of "+
        	"this monstrousity and lit to make heat for cooking on the top of the stove "+
        	"and for baking other foods in the baking box.\n",
        "pantry" : "\n%^RESET%^This is a small closet where non-perishable food stuffs "+
        	"are kept.\n"
        ]));

    set_door("door",LROOMS+"leadine","south","brass key");
    set_string("door","open","The door swings open to the dining room.\n");

    set_exits(([
	"south" : LROOMS+"leadine"
    ]));
}