#include <std.h>
#include "../antioch.h"
#include <daemons.h>

inherit CVAULT;

void create()
{
    set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }) );
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
        set_property("indoors",0);
        set_property("light",2);
        set_short("An intersection");
        	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
        ]));
        set_exits(([
        "east" : ROOMS+"church1",
        "west" : ROOMS+"street21",
        "north" : ROOMS+"street13",
        "south" : ROOMS+"street15"
        ]));
}

void reset()
{
        ::reset();
        if(!present("street_light")) {
                new(OBJ+"street_light")->move(TO);
        }
}
