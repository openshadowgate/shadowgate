#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(STAIRWAY);
    set_name("bedroom");
    set_short("bedroom");
    set_long("This is a  room off of the balcony.  There is a bed in the center.  Also, there is an area sectioned off as a closet.  Like the rest of the tower the walls, floor and ceiling are made of onyx.");
    set_smell("default","The air is clean but somewhat stuffy");
    set_listen("default","your own footsteps echo through this place");

    set_items(([
        "bed" : "This is a large comfy bed.",
        "closet" : "The closet is huge, plenty of room for clothing and storage.",
    ]));
    set_exits(([
        "out" : ROOMS"tower2",
    ]));
    set_door("door",ROOMS"tower2","out",0);
    set_door_description("door","An ornate wooden door.");
}
