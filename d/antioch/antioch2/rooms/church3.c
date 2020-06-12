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
	set_short("%^BOLD%^Grand Church of Antioch");
	set_long(
	"The church has been destroyed, but you seem to be able to make your way upstairs, if you really wanted to."
	);
	set_smell("default","It smells of death.");
	set_listen("default","It is silent like the grave.");
	set_items(([
	({"sconce","sconces","stone sconces"}) : "The sconces are carved"+
	" out of the stone blocks themselves, actually part of the wall."+
	" They are shaped like roses, and they hold"+
	" incense.",
	"incense" : "There are sticks of incense in the sconces along"+
	" the walls. The incense has a curious relaxing quality to it"+
	" and you feel safe and at peace because of it.",
	({"stone","stones","blocks","stone blocks","stone block"}) : "The"+
	" entire building is made out of perfectly made stone blocks. They"+
	" have been flawlessly joined together and mortar smooths in the"+
	" gaps to keep the wind out.",
	"floor" : "The floor is also made out of the perfectly connecting"+
	" stone blocks and looks to be kept quite clean.",
	"doorway" : "The doorway here shows that the stone blocks used to"+ 	" create this building are at least a foot in thickness. You can't"+
	" imagine anything capable of breaking through the walls.",
	"mortar" : "Gray mortar fills in the tiny gaps between the stone"+
	" blocks. It is almost so perfectly the color of the stone that"+
	" you can hardly tell it's there.",
	({"stairs","stone stairs","stair case","staircase"}) : "The large"+
	" stone stair case here winds up at least one level. You can't"+
	" see much of the ceiling from this view, the stair case simply"+
	" seems to go on forever. It is made out of large stone blocks"+
	" that look very sturdy.",
	]));
	set_exits(([
	"south" : ROOMS+"church1",
	"up" : ROOMS+"church7",
	]));
}
