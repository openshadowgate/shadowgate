// /d/antioch/village/t3.c

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
%^RED%^Ignatius spent his days helping the citizens of Antioch.  He was
known throughout the land as a benevolent wizard.  While he was
not the ruler of Antioch, the village would not have been able to
exist without the favor of Ignatius.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits(([
    "up":VIL+"t4",
    "down":VIL+"t2"
  ]));
}

void init() {
   ::init();
  do_random_encounters(({
    MON+"demon"
  }),50,2);
}
