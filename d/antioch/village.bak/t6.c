// /d/antioch/village/t6.c

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
%^GREEN%^You see, not so very long ago, Ignatius sensed that he was going mad.
Brought on by the horrors of his lifetime, Ignatius had known it was only
a matter of time.  In preparation, he enchanted this very tower - in order
that he might protect the village he once loved.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits(([
    "up":VIL+"t7",
    "down":VIL+"t5"
  ]));
}
