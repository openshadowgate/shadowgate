#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Second floor of a Grand Church");
	set_long(
	"The church is in ruins, but you could make your way south or north if you wanted to."
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
	({"stairs","stone stairs","stair case","staircase"}) : "There are"+
	" stairs that you can see both to the north and south. The"+
	" ones to the south look like they lead up to the third floor"+
	" and the ones to the south can go down to the first floor or up"+
	" to the third it seems."
	]));
	set_exits(([
	"north" : ROOMS+"church7",
	"south" : ROOMS+"church9",
	"east" : ROOMS+"church11"
	]));
	set_door("door",ROOMS+"church11","east",0);
      set_door_description("door","The wooden door set into the eastern wall has "
         "been carved with various symbols of the faith, mostly likely by the acolytes.");
}
