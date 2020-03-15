// /d/antioch/village/t9.c

inherit"/std/room";
#include "/d/antioch/areadefs.h"

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Dark Tower");
  set_long(
@ANTIOCH
%^BOLD%^You are in the Dark Tower%^RESET%^
%^MAGENTA%^As his final and most horrific reminder to the inhabitants of Antioch,
Ignatius caused blood to pour forth from the village fountain.  While this
apparently did not dissuade you in your quest, the villagers were driven
away in terror.
ANTIOCH
  );
  set_smell("default","You smell old brick.");
  set_exits( ([
    "up":VIL+"t10",
    "down":VIL+"t8"
  ]));
}

void init(){
  ::init();
  do_random_encounters(({
    MON+"skeleton",
    MON+"demon"
  }),70,3);
}
