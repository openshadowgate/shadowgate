//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Staircase");
    set_long(
    "%^GREEN%^"+
    "The stairs up to the ground level are on the east side of the room and coverd with a "+
    "long %^RED%^red%^GREEN%^ rug. On the west side a set of stairs leads down to a "+
    "lower floor. The downward stairs are plain unadorned stone. To the north you can see "+
    "two doors at the end of the short hallway. There are torches placed on the walls so "+
    "the room is quite well lit, and you can see that the level below this one seems to be "+
    "cut out of the mountain itself.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Only dust tickles your nose.");
    set_listen("default","It is quiet here.");
    set_exits(([
	"north" :MROOMS+"meldh1",
	"down" :MROOMS+"melgua",
	"up" :MROOMS+"mel5"
    ]));
}
