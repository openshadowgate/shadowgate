// /d/antioch/village/t1.c

inherit"/std/room";
#include "/d/antioch/areadefs.h"

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("You are in a huge tower.");
set_long(
@ANTIOCH
%^BOLD%^You are in the Dark Tower%^RESET%^
You now see that the villagers do not maintain the inside of the tower
as well as they do the outside.  The brick walls seem to be crumbling
before your eyes, and small rodents have the run of the place.  You
wonder if there is something that keeps the villagers out of this
place.
ANTIOCH
);
  set_smell("default","You smell old brick.");
  set_exits(([
    "up":VIL+"t2",
    "out":VIL+"e1"
  ]));
}
