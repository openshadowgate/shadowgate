#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
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
	"fountain" : "There is a large fountain to the west.",
	"church" : "A very impressive stone church sits at the eastern"+
	" end of this street.",
	"shops" : "There are many shops on this street.",
	]));
	set_exits(([
	"west" : ROOMS+"fountain",
	"east" : ROOMS+"street21",
	"north" : ROOMS+"weapon",
	"south" : ROOMS+"armor",
	]));
	set_door("oak door",ROOMS+"weapon","north",0);
	set_door("cherry door",ROOMS+"armor","south",0);
	if(query_night() == 1) {
		set_open("cherry door",0);
		set_open("oak door",0);
		"/d/antioch/antioch2/rooms/armor"->set_open("cherry door",0);
		"/d/antioch/antioch2/rooms/weapon"->set_open("oak door",0);
	}
	else if(query_night() != 1) {
		set_open("cherry door",1);
		set_open("oak door",1);
		"/d/antioch/antioch2/rooms/armor"->set_open("cherry door",1);
		"/d/antioch/antioch2/rooms/weapon"->set_open("oak door",1);
	}
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
	if(query_night() == 1) return;
	else if(!present("citizen")) {
             switch(random(4)) {
			case 0:
				new(MONS+"citizen1")->move(TO);
				break;
			case 1:
				new(MONS+"citizen2")->move(TO);
				break;
			case 2:
				new(MONS+"citizen3")->move(TO);
				break;
			case 3:
				new(MONS+"citizen4")->move(TO);
				break;
		}
	}
}
