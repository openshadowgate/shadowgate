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
	set_short("Apple Street");
	set_long(
	"You are on Apple street.\n"+
	"A jeweler's shop is nestled here at the western corner."+
	" A wooden sign hangs over the entrance way, proclaiming"+
	" it a jeweler's shop. To the north there is the side of"+
	" a building, and you can hear loud laughter and slurred"+
	" toasts coming from it. To the east Apple street continues"+
	" to intersect with Oak and Cedar, and there is a tailor's"+
	" shop across the way. Apple street continues to the"+
	" southwest to intersect with Cherry and Pine outside the"+
	" stables."
	);
	set("night long",
	"You are on Apple street.\n"+
	"To the east is a crossroads where Oak, Apple, and Cedar"+
	" intersect. A street light there sheds light onto the"+
	" surrounding areas. To the west is a house with the symbol"+
	" of a jeweler's over the entrance. Inviting yellow light"+
	" spills forth from beneath the door. Directly north is the"+
	" side of a large building. You can hear chatter and drunken"+
	" laughter from within, but there is no entrance to it on"+
	" this street. To the southwest Apple street continues on"+
	" to meet with Cherry and Pine by the stables."
	);
	set_smell("default","There is the faint scent of oil hanging"+
	" in the air.");
	if(query_night() == 1) {
		set_listen("default","You can hear the sound of rowdy men"+
		" to the north.");
	}
	else {
		set_listen("default","The hustle and bustle of a busy"+
		" city surrounds you.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Apple street.",
	"sign" : "There's a wooden sign with the symbol of a jeweler"+
	" hanging over the doorway of the shop on the west. It also has"+
	" the image of falling star sapphires on it, declaring it the"+
	" Falling Stars Jewelry.",
	]));
	set_exits(([
	"east" : ROOMS+"street10",
	"west" : ROOMS+"jeweler",
	"southwest" : ROOMS+"street8",
	]));
	set_door("door",ROOMS+"jeweler","west",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/jeweler"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/jeweler"->set_open("door",1);
	}
}
