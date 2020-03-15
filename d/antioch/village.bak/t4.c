// /d/antioch/village/t4.c

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
%^BLUE%^For countless years, Ignatius watched over the people of Antioch
from his great tower.  In time, the villagers came to see him as a
sort of god.  
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits( ([
    "up":VIL+"t5",
    "down":VIL+"t3"
  ]));
}
