#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Pine Street");
	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_items(([
	"street sign" : "This is Pine Street.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"sign" : "This is a wooden sign with the symbol of a leather"+
	" worker on it. It hangs above the doorway to the house on the"+
	" west.",
	({"tower","guard tower"}) : "The stone guard tower is to"+
	" the southeast.",
	]));
	set_exits(([
	"southeast" : ROOMS+"street2",
	"northwest" : ROOMS+"street4",
	"west" : ROOMS+"leather",
	]));
	set_door("door",ROOMS+"leather","west",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/leather"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/leather"->set_open("door",1);
	}
}
