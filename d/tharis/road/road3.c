 //d/tharis/road/road3.c//
#include <std.h>
#include <objects.h>
inherit ROOM;
void create() {
    room::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("Road between Darkwood and Tharis.");
    set_long(
@OLI
        To the south is the grand trade city of Tharis and to the north is 
the road to Darkwood. The forest looms around you. You marvel at the
rumours of the Elven civilization which lives in the forest. To the south
you can see the grand towers of the city of Tharis, made rich by its
exploitation of its natural resources.
OLI
    );
set_smell("default","The wonderful fragrances of the forest waft through your senses.");
set_listen("default"," There is an unnatural quiet about the forest.");
    set_exits(([
"south" : "/d/tharis/road/road4",
       "north" : "/d/tharis/road/road2"
    ] ));
    set_items(([
       "road" : "The road is deeply rutted by the eons of travle by heavily laden wagons of
trade.",
"forest":"The forest is impenetrable around you, yet it seems to call for help."
    ] ));
} 
