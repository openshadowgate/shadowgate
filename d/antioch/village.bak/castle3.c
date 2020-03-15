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
"This part of the castle is a favorite hangout for adventurers. "
"Yet an unwanted amount of zombie guards pass through here to pester "   
"inexperienced players.  You hear soothing poetry to the east which causes "  
"a rapture like feeling.\n"
);
     set("night long",
     "\n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"%^CYAN%^It is very cold.\n"
"No adventurers stay here at night for some odd reason?  Yet you find it "
"very friendly and calm here and wish to stay.  Poetry fills your ears, and "
"the sounds of a grandfather clock can be heard.\n"
);
     set_smell("default", "You smell dust from the statue.\n");
     set_listen("default", "You hear poetry to the east.\n");
  set_exits(([
    "east": CASTLE+"castle4",
    "west":CASTLE+"castle2"
]));
}

