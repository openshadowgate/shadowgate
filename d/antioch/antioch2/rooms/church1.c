#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Entrance of Antioch's Grand Church");
	set_long(
	"The church has been destroyed. You see a treacherous stairway to the north."
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","You hear the sounds of your worst nightmares.");
	set_items(([
	({"stone","stones","blocks","stone blocks","stone block"}) : "The"+
	" entire building is made out of perfectly made stone blocks. They"+
	" have been flawlessly joined together and mortar smooths in the"+
	" gaps to keep the wind out. Standing in the entrance way you"+
	" can see that the stones are quite thick, about a foot deep. It"+
	" must have been some work to build this impressive church.",
	"floor" : "The floor is also made out of the perfectly connecting"+
	" stone blocks and looks to be kept quite clean.",
	"ceiling" : "The ceiling is made out of the smooth stone blocks."+
	" They look as though they are held well in place, but they"+
	" would surely crush anything they should happen to fall upon.",
	({"archway","doorway"}) : "The archway here shows that the stone"+
	" blocks used to create this building are at least a foot in"+
	" thickness. All the doorways are arched in a curving manner and"+
	" none of them actually have doors. This church is a sanctuary"+
	" to all who deserve protection.",
	"mortar" : "Gray mortar fills in the tiny gaps between the stone"+
	" blocks. It is almost so perfectly the color of the stone that"+
	" you can hardly tell it's there.",
 	({"step","steps","stone steps"}) : "A few small stone steps lead"+
	" to the east, which appears to be the main altar area.",
	({"passageway","passageways"}) : "There are two passageways here,"+
	" one leads to the north and the other to the south.",
	]));
	set_exits(([
	"west" : ROOMS+"street14",
	//"south" : ROOMS+"church2",
	"north" : ROOMS+"church3", //keeping this for the quest.
	//"east" : ROOMS+"church4",
	]));
}
