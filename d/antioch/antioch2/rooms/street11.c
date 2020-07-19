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
	"You are on Cedar street.\n"+
	"A wooden sign hanging over the doorway of the house on"+
	" the east marks it as the shop of a tailor. The door is"+
	" open for all and you can see many types of fabric and"+
	" measuring instruments scattered about inside. To the north"+
	" is the side of the inn. You can see a few windows on the"+
	" second floor that overlook the city. To the west is the"+
	" intersection of Cedar, Oak, and Apple. At the end of the"+
	" street there appears to be a jeweler's shop. Cedar street"+
	" runs to the southeast and turns south to intersect with"+
	" Crescent and Cherry."
	);
	set("night long",
	"You are on Cedar street.\n"+
	"The street lights to the west and southeast shed light"+
	" on the area. The windows on the second floor of the"+
	" building to the north are also brightly lit, and spill"+
	" their light out onto this street. There is also a light"+
	" coming from the house on the east. Above the doorway of"+
	" the house is a wooden sign with the symbol of a tailor."+
	" To the west Cedar intersects with Apple and Oak in a"+
	" crossroads. At the end of the street to the west you can"+
	" see a jeweler's shop. Cedar street runs to the southeast"+
	" and turns south to intersect with Crescent and Cherry."
	);
	set_smell("default","The scents of various foods drift to"+
	" you on the breeze.");
	if(query_night() == 1) {
		set_listen("default","You can hear the faint sounds of"+
		" drunken laughter.");
	}
	else {
		set_listen("default","A woman is humming a merry tune"+
		" in the tailor's shop.");
	}
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
