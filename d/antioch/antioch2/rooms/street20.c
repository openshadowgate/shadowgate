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
	"You are on Cherry street.\n"+
	"This is the main street through town and there are lots of"+
	" shops on it. There is even a little bank back to the west,"+
	" just south of the large fountain. To the north there is"+
	" a weapons shop, with a sign hanging over the doorway with"+
	" a picture of a serrated mace on it. To south is the shop of"+
	" an armorer with a sign declaring it the %^BOLD%^Silver%^RESET%^"+
        " Gauntlet. At the end of the street to the east there is a very large"+
	" and beautiful church. Just in front of the church Crescent"+
	" and Cedar intersect with Cherry. Crescent street runs to"+
	" the southwest towards the Antioch gates, and Cedar street"+
	" runs to the northwest to meet with Oak street. Oak street"+
	" runs from the fountain straight north to the palace."
	);
	set("night long",
	"You are on Cherry street.\n"+
	"A street light here sheds a warm yellow glow on the area."+
	" Most of the shop owners have all gone to bed and closed"+
	" shop for the night. Both the door to the armory on the"+
	" south and the weapons shop on the north are closed. There"+
	" is a faint light coming from beneath the doorway, though,"+
	" and if you really needed something you might be able to"+
	" wake one of them up. To the west there is a large fountain"+
	" and just south of it is the bank, which appears to be open"+
	" still. To the west is a large stone church. Inviting"+
	" light spills forth from its large archway, a sanctuary"+
	" for all at any time."
	);
	set_smell("default","The smell of oil is thick in the air.");
	if(query_night() == 1) {
		set_listen("default","The gentle gurgling of the fountain"+
		" is all that can be heard.");
	}
	else {
		set_listen("default","The sounds of shoppers haggling"+
		" for better prices surrounds you.");
	}
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
