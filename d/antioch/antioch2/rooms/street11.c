#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Cedar Street");
	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cedar street.",
	"sign" : "This wooden sign is hung above the doorway to the"+
	" house on the east and has the symbol of a tailor on it. It also"+
   " has a picture of a golden sewing needle, proclaiming it as The Golden Needle.",
	"house" : "This is a sturdy wooden house.",
	"shop" : "This is a tailor's shop.",
	]));
	set_exits(([
	"west" : ROOMS+"street10",
	"east" : ROOMS+"tailor",
	"southeast" : ROOMS+"street12",
	]));
	set_door("door",ROOMS+"tailor","east",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/tailor"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/tailor"->set_open("door",1);
	}
}
