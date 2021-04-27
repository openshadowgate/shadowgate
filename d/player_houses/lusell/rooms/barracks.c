//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("barracks");
	set_short("barracks");
	set_long(
		"This room is large and houses several bunkbeds.  By each "+
		"set of beds are two footlockers.  This room is very clean, "+
		"but there is the underlying odor of many men spending time "+
		"in one room for extended periods of time.  In the south end "+
		"of the room are chairs and a table.  On the table is a well "+
		"worn deck of cards.\n"
	);
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room looks clean, but has the odor of many men.");
	set_listen("default","Sounds in this room echo off the walls.");
	set_items(([
		({"bed","bunkbed","beds","bed"}) : "The beds have enough padding "+
			"to make your nights sleep restful, but not enough to get "+
			"comfortable over long periods of time.\n",
		({"footlockers","footlocker"}) : "The chest is rectangular, made of wood, and "+
			"will store much of a guards personal belongings.\n",
		({"chairs","chair","table"}) : "This table can easily seat ten men "+
			"at a time with more than twice that in chairs scattered about.\n",
		"cards" : "The cards have seen better days, some of the cards are "+
			"barely recognizable and even more have been dog-eared, or are "+
			"just plain missing parts.\n"
   ]));
  	set_exits(([
		"north" : LROOMS+"hall5"
	]));

  	set_door("south door",LROOMS+"hall5","north","ruby key");
   set_door_description("south door","A simple wooden door.\n");
   set_string("south door","open","The door opens into a large hallway.\n");
   set_open("south door",1);

}
