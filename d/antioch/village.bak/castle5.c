inherit "/std/room";
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(
     " \n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"This room is filled with creatures which seem to be guarding the hall to "  
"to the east.  The hall seems to be very dark and dry.  An odd "
"amount of plant life is here, yet hardly any of it is alive.\n"
);
     set_smell("default", "You smell dust from the statue.\n");
       set_listen("default", "You hear poetry to the west.");
     set_exits( ([
       "east": CASTLE+"castle6",
       "west": CASTLE+"castle4"
]));
}

