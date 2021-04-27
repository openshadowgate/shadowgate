//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit ROOM;

void create(){
    ::create();
  set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_short("Castle Stable");
    set_long(
    "%^ORANGE%^"+
    "This is a small stable where visitors can safely leave their horses.  Hay and water "+
    "are conveniently provided as well as brushes and other gear for grooming the animals.  "+
    "There is room for no less than 6 horses.  In the northwest corner you can see a door "+
    "which leads in the stable hands living quarters.  This is just the kind of stable you "+
    "would expect to see a young boy working in.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You can smell hay and horses");
    set_listen("default","Sounds of the stablehand can be heard coming from the backroom.");
    set_items(([
    	"hay":"It's %^BOLD%^%^ORANGE%^hay%^RESET%^...what did you think it was?",
	"water":"Good %^BOLD%^%^BLUE%^water%^RESET%^ for the horse, but I wouldn't want to "+
			"try it."
	]));
    set_exits(([
	"east" :MROOMS+"mely"
    ]));
}
