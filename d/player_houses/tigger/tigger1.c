// tigger1.c
//
// Tigger's house

#include <std.h>
inherit VAULT;

void create(){
    ::create();
    set_short("Entrance to a burrow");
    set_long(
@DESC
You are just to the west of a small canyon. You can see the canyon
winding down into darkness. The canyon walls are almost hidden by
sand dunes. As you pass through the canyon, you see a small house.
DESC
    );
    set_indoors(0);
    set_light(2);
    set_smell("default","The smell of the flowers on the roof spreads out.");
    set_listen("default","You hear something bubbling from inside the house.");
    set_items((["house":"As you look at the house, you realize it's a Halfling burrow. It is built completely from stones carried and carved into a decent looking structure. The roof is covered with moss and grass. The burrow has small windows that on hot summer days always are open. In front of you is a small door that most people would have trouble entering without bending down or crawling. You see smoke puffing from a small chimney on the roof."]));
    set_exits(([
        "enter":"/d/player_houses/tigger/tigger2",
        "east":"/d/islands/pirates/caves/canyon1",
    ]));
    set_door("door","/d/player_houses/tigger/tigger2","enter",0);
    set_open("door",1);
}

void reset(){
   ::reset();
   set_open("door",1);
   "/d/player_houses/tigger/tigger2"->set_open("door",1);
}


