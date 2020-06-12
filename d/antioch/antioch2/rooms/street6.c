#include <std.h>
#include "../antioch.h"

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
        set_items(([
        "street sign" : "You are at the intersection of Apple, Cherry"+
        " and Pine.",
        "sign" : "There is a wooden sign with the symbol of a stables"+
        " hanging over the doorway of the building on the west.",
        ({"stables","building"}) : "This large building appears to be a stables.",
        "fountain" : "There is a large fountain in the middle of"+
        " Cherry street.",
        "church" : "At the end of Cherry street there appears to be"+
        " a large church.",
        ({"street","cobblestones","cobbles","road","path"}) : "The"+
        " street is paved with cobblestones.",
        ]));
        set_exits(([
        "west" : ROOMS+"stables",
        "east" : ROOMS+"street18",
        "north" : ROOMS+"street7",
        "south" : ROOMS+"street5",
        ]));
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
