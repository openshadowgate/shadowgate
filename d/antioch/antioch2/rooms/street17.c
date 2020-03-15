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
	set_short("Crescent Street");
	set_long(
	"You are on Crescent street.\n"+
	"On the east there's a little house here. A strong scent of"+
	" dried meats and fruits seems to come from within it. To the"+
	" northeast you can see a very large stone church that causes"+
	" the street to turn to the north. To the southwest is the"+
	" intersection of Crescent and Pine street, not far from the"+
	" Antioch gates."
	);
	set("night long",
	"You are on Crescent street.\n"+
	"Dim yellow light seeps through from underneath the doorway of"+
	" the house on the east here. The house isn't too big, it"+
	" is made of wood and has a sturdy brown roof. The strong smell"+
	" of dried meats and fruits comes from it. The street lights"+
	" along the rest of the street help to shed some light here."+
	" To the southwest Crescent meets with Pine street, to the"+
	" northeast you can see a large stone church just before the"+
	" street curves to the north."
	);
	set_smell("default","You can smell dried meat and fruits.");
	if(query_night() == 1) {
		set_listen("default","You hear gentle snores coming"+
		" from inside the little house.");
	}
	else {
		set_listen("default","The hustle and bustle of a busy"+
		" city is all around you.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Crescent street.",
	({"house","building","shop"}) : "It is a small little wooden"+
	" house with a pretty brown roof.",
	"church" : "There is a very impressive stone church to the"+
	" northeast.",
	]));
	set_exits(([
	"northeast" : ROOMS+"street16",
	"southwest" : ROOMS+"street2",
	"east" : ROOMS+"ration",
	]));
	set_door("door",ROOMS+"ration","east",0);
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/ration"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/ration"->set_open("door",1);
	}
}
