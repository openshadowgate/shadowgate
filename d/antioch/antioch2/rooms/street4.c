#include <std.h>
#include "../antioch.h"

inherit CVAULT;

void create()
{
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }) );
        ::create();
        set_travel(PAVED_ROAD);
        set_terrain(CITY);
        set_property("indoors",0);
        set_property("light",2);
        set_short("Pine Street");
		set_long(
		"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
		);
		set_smell("default","It smells of death and decay.");
		set_listen("default","The city is dead.");
        set_items(([
        ({"street","cobblestones","cobbles","road","path"}) : "The"+
        " street is paved with cobblestones.",
        "street sign" : "This is Pine street.",
        ]));
        set_exits(([
        "northwest" : ROOMS+"street5",
        "southeast" : ROOMS+"street3",
        ]));
}

void reset()
{
        ::reset();
        if(!present("street_light")) {
                new(OBJ+"street_light")->move(TO);
        }
}
