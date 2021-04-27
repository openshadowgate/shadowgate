#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("Tower");
    set_short("Tower");
    set_long("Granite steps lead up to a stout metal door, the entrance to the tower here.  The steps have many etchings on them as does the inlet leading to the door.  The door itself is covered with seven star-shaped crystals.  Grass and rocks of the garden are present to the south as it the granite wall.");
    set_smell("default","The air is clean here and it smells of fresh grass.");
    set_listen("default","It is quiet except for the sounds of birds off in the distance.");

    set_items(([
        ({"tower","onyx tower"}) : "This tower looks to be made out of onyx, the top is only slightly more narrow than the bottom.  The sides are ribbed with several outcroppings that go from the base to the top.  Four pointed tips jut outwards and up at the top of the tower, they look almost claw-like.",
        "stone" : "There are blocks of stone about, grass grows around them and they are buried some more than others.",
    ]));
    set_exits(([
        "northeast" : ROOMS"garden5",
        "northwest" : ROOMS"garden3",
        "north" : ROOMS"tower1"
    ]));
    set_door("door",ROOMS"tower1","north",0);
    set_door_description("door","Steps lead up to an ornate metal door.  It is the only visible entrance to the tower.");
}

void reset() {
   ::reset();
   if(!present("blade golem")) new("/d/player_houses/valas/mon/bgolem2")->move(TO);
}
