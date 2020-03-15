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
"Now the castle starts to extend.  Monsters of every shape and size can be "
"heard and seen from here.  A dark feeling runs through your body as you "
"look around you."
);     
     set_smell("default", "You can smell the stones.\n");
     set_exits(([
  "south": CASTLE+"castle6",
       "east":CASTLE+"castle8"
]));
     set_items(([
({"clock"}):
"It seems to be a grandfather clock.",
({"statue"}):
"This is a huge statue of a zombie."
]));
}
void init() {
     ::init();
do_random_encounters(({
"/d/antioch/mon/zombie.c",
"/d/antioch/mon/painting.c"
}),50, 1);

}

