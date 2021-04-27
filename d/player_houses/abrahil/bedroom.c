//Coded by Styx for Abrahil
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("Bedroom");
    set_short("A simple bedroom");
    set_long("This is obviously the sleeping chamber of the one who lives here.  A %^ORANGE%^simple pine bed %^RESET%^sits in the center of the room and a small night stand sits beside it.  Upon the night stand is a %^CYAN%^half-melted candle%^RESET%^.  A chair sits in the corner and it has clothing draped over it.  The floor of this chamber feels like slightly wet mud.");
   set_items(([
    "bed" : "This is a nicely carved but otherwise rather plain pine bed.  It is "
       "not kept well and seems to be well used.", 
    "nightstand" : "The nightstand has a few things upon it, but nothing is of
interest but the candle.",
    "candle":"%^CYAN%^The candle seems to be of a strange wax, it is half melted.",
    "chair" : "The chair in this room is a simple wooden chair.  It has clothes "
       "draped over it.",
    "clothes" : "The clothes are simply tailored and well worn but not tattered.",
    ] ));
    set_exits(([
       "southeast" : "/d/player_houses/abrahil/kitchen",
    ] ));
   set_smell("default","You smell the moist earth.");
   set_listen("default","All sound seems to be muted by the earthen walls.");
}