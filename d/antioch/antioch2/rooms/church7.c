#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Second floor of a Grand Church");
	set_long(
	"The church is in ruins, but you could make your way south if you wanted to."
	);
	set_smell("default","It smells of death.");
	set_listen("default","It is silent like the grave.");
	set_items(([
	({"rug","thin rug","floor"}) : "A thin rug stretches down the length of"+
	" the hallway. It is decorated in concentric rectangular shapes"+
	" of multiple colors and is kept very clean.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps hang from"+
	" small metal circles that are placed in the ceiling at intervals"+
	" all the way down the hallway, giving light to the place.",
	"incense" : "Sticks of incense are placed in holders on the western"+
	" wall. They are a rich cinammon color and smell of of spiced"+
	" apples.",
	"ceiling" : "Metal circles are placed at intervals along the"+
	" ceiling and oil lamps hang from them.",
	({"incense holder","incense holders"}) : "Pewter incense holders"+
	" are placed at intervals along the western wall.",
	({"stairs","stone stairs","stair case","staircase"}) : "The large"+
	" stone stair case here leads down to the first level as well as"+
	" spiraling up to at least another level. It is made out of large"+
	" stone blocks that look very sturdy.",
	"door" : "There is a plain wooden door on the eastern wall here."+
	" It is engraved with the symbol of a novice acolyte.",
	]));
	set_exits(([
	"down" : ROOMS+"church3",
	"south" : ROOMS+"church8",
	//"up" : ROOMS+"church13",
	//"east" : ROOMS+"church12",
	]));
	set_door("door",ROOMS+"church12","east",0);
}
