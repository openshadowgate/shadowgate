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
	set_short("Crescent Street");
	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_exits(([
	"north" : ROOMS+"street14",
	"southwest" : ROOMS+"street16",
	]));
}
