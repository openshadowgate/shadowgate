#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(STAIRWAY);
    set_name("tower");
    set_short("tower");
    set_long("This rather large common area is designed as a place of meeting and for entertaining guests.  There is a stairway that leads up to a balcony which overlooks about half of the room.  Like the rest of the tower most everything is made of onyx.  There is a giant fountain in the middle of the room.  Towards one side there is a large onyx table surrounded by wooden chairs.");
    set_smell("default","The air is clean but somewhat stuffy.");
    set_listen("default","Your own footsteps echo through this place.");

    set_items(([
        ({"stairway","stairs"}) : "Two sets of stairs round their way up to a balcony.",
        "balcony" : "It overlooks the room, there is an etched railing for safety.",
        "fountain" : "A statue of the lady of magic stands here in a flowing robe, water sprouts from her head in such a way that it looks like her hair is flowing water.",
        "table" : "A large onyx table surrounded with chair.  It is a place of meeting.",
    ]));
    set_exits(([
        "up" : ROOMS"tower3",
        "down" : ROOMS"tower1",
        "enter" : ROOMS"bedroom",
    ]));
    set_door("door",ROOMS"bedroom","enter",0);
    set_door_description("door","An ornate wooden door.");
}
