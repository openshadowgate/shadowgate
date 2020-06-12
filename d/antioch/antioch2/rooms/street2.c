#include <std.h>
#include <daemons.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
   object ob;
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A cobbled street");
	set_long("A cobbled street.\n"+
	"%^BOLD%^%^BLACK%^The city lies in ruins, covered in a dark, black haze. To the southwest, a gaping hole has opened up into the abyss. Tendrils of darkness spew out from it, blanketing the world in shadows. %^RED%^Even here, you feel your skin begin to boil and your soul is slowly crushed by terrible nightmares. %^RESET%^");
    set_smell("default","The smell of death hangs in the air.");
    set_listen("default","You hear the sound of your worst nightmares to the west.");
	set_items(([
	"sign" : "There is a wooden sign here with the symbol of"+
	" a Healer engraved on it. It hangs in front of little hut"+
	" on the west.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	({"tower","guard tower"}) : "This is a great stone guard"+
	" tower.",
	"street sign" : "You are at the intersection of Pine and"+
	" Crescent street. Pine runs along the northwest and Crescent"+
	" runs up to the northeast.",
	]));
	set_exits(([
	"south" : ROOMS+"street1",
	"west" : ROOMS+"healer",
	"east" : ROOMS+"gtower",
	"northwest" : ROOMS+"street3",
	"northeast" : ROOMS+"street17",
	]));
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id(({"board","bulletin board","antioch board","Antioch board"}));
   ob->set_board_id("union_board");
   ob->set_short("Arcane Bulletin Board");
   ob->set_long("This is a large board where people can discuss relevant issues about the town.");
   ob->set_max_posts(30);
   ob->set_queue(1);
   ob->set_location(ROOMS+"street2");
}

void reset() {
	::reset();
	if(!present("street_light")) new(OBJ+"street_light")->move(TO);
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

void init() {
   ::init();
}

