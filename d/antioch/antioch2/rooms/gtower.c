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
	"%^BOLD%^%^BLACK%^The guard tower has been destroyed. Large stone steps lead to nothing and above you  You do notice an exit into the wrecked garden of Jarmila's ruined temple, however.%^RESET%^"
	);
	set_smell("default","The sweat of soldiers permeats the room.");
	set_listen("default","The guards are idly chatting.");
	set_items(([
	({"steps","stairs","stone steps"}) : "The large stone stairs have fallen down.",
	]));
	set_exits(([
	"west" : ROOMS+"street2",
	//"stairs" : ROOMS+"gtower2",
	"east" : "/d/magic/temples/jarmila/jarmilaentry.c"
	]));
}
