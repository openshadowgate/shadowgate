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
	set_short("A guard tower");
	set_long(
	"%^BOLD%^%^BLACK%^The guard tower has been destroyed. The ruined stairs lead to nothing but a wrecked hole in the ceiling.%^RESET%^"
	);
	set_smell("default","The sweat of soldiers permeats the room.");
	set_listen("default","The guards are idly chatting.");
	set_items(([
	({"steps","stairs","stone steps"}) : "The large stone stairs have fallen down.",
	]));
	set_exits(([
	"west" : ROOMS+"street2",
	"stairs" : ROOMS+"gtower2",
	]));
}
