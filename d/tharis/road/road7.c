 //d/tharis/road/road7.c//

#include <std.h>

inherit ROOM;
void create() {
    ::create();	
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("Bridge on the road to Darkwood");
    set_long(
@OLI
        To the south is the grand trade city of Tharis and to the north is 
the road to Darkwood.  The forest looms around you.  You marvel at the
rumours of the Elven civilization which lives in the forest.  To the south
you can see the grand towers of the city of Tharis, made rich by its
exploitation of its natural resources.  This bridge rises over the river
and allows travel to continue north and south in spite of it.  To the 
southeast you can see a dock where the river ferries dock to transport
people and goods on the Sarcosta River.
OLI
    );
    set_smell("default","The wonderful fragrances of the forest waft through your senses.");
    set_listen("default","There is an unnatural quiet about the forest.");
    set_exits(([
	"south" : "/d/tharis/road/road8",
	"north" : "/d/tharis/road/road6",
	"southeast" : "/d/shadow/virtual/river/tharis.dock"
    ] ));
    set_items(([
        "road" : "The road is deeply rutted by the eons of travel by heavily laden wagons of
trade.",
	"forest":"The forest is impenetrable around you, yet it seems to call for help."
    ] ));
}
