// /d/antioch/village/t5.c

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
%^ORANGE%^The statue at the entrance to the village... yes, that was originally erected
in honor of Ignatius.  Only recently has the fountain begun to spout blood
in place of water, frightening many of the villagers.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
set_exits( ([
    "up":VIL+"t6",
    "down":VIL+"t4"
]) );
}

void init(){
  ::init();
  do_random_encounters(({
    MON+"zombie",
    MON+"demon"
  }),80,1);
}
