// /d/antioch/village/t8.c

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
%^RED%^While fading in and out of sanity, Ignatius found that he had cast a
spell over the village of Antioch, turning many of its residents into undead.
In a final moment of clarity, Ignatius realized his actions, and the world
trembled with his rage.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits(([
    "up":VIL+"t9",
    "down":VIL+"t7"
  ]));
}
