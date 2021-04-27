//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Altar room");
    set_long(
    "%^BOLD%^%^BLACK%^"+
    "This room was once a place of worship, but now is a blackened shell of a room.  "+
    "The walls are covered with soot and the once beautiful altar lays in rubble.  "+
    "Broken candlesticks litter the floor and the censera are laying on their side, "+
    "the metal all bent and useless.  The once beautiful high windows are covered "+
    "with soot and grime and no light filters through the glass.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",1);
    set_smell("default","Your nose is filled with the smell smoke and ash.");
    set_listen("default","It is deathly quiet.");
    set_items(([
	"altar":"The altar is was made from a single huge, smooth block of %^BOLD%^%^BLACK%^"+
		"obsidian%^RESET%^.  There are no symbols, markings or scratches of any kind "+
		"and the surface is very clean.  The altar lies broken upon the floor.",
	({"censer","censers"}):"Metal bowls once placed upon stands for the purpose "+
		"of burning incense now lies twisted and broken on the floor."
	]));

    set_door("door",MROOMS+"mel6","east","mithril key");
    set_door_description("door","A normal %^ORANGE%^wooden%^RESET%^ door with deep "+
    	"burn marks from an intense fire stands before you.");
    set_string("door","open","The door swings open, with squeaking reluctance, "+
    	"allowing you back into the hallway.\n");

    set_exits(([
	"east" :MROOMS+"mel6"
    ]));
}
