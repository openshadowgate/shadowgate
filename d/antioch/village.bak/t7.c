// /d/antioch/village/t7.c

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
While Ignatius' preparations provided for his containment, even he could
not have forseen the power of his great transformation.  Sensing that
he was losing control, Ignatius placed guards in and around his 
tower, to keep people away from him.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits(([
    "up":VIL+"t8",
    "down":VIL+"t6"
  ]));
}
