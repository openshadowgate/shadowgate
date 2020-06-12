#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Cherry Street");
		set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cherry street.",
	"fountain" : "A large fountain is in the center of the Cherry"+
	" street.",
	"church" : "There is a very impressive stone church to the"+
	" east.",
	]));
	set_exits(([
	"west" : ROOMS+"street20",
	"east" : ROOMS+"street14",
	]));
}
