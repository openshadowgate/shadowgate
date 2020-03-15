// /d/antioch/village/t2.c

inherit"/std/room";
#include "/d/antioch/areadefs.h"

void create(){
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("You are in a huge tower.");
  set_long(
@ANTIOCH
%^BOLD%^You are in the Dark Tower%^RESET%^
%^GREEN%^A story was once told about a tower in the northern part of Antioch
which has been enchanted by an evil spell.  The good wizard Ignatius,
once god of Antioch, sat in his chair protecting Antioch from evil.
ANTIOCH
  );
  set_exits(([
    "up":VIL+"t3",
    "down":VIL+"t1"
  ]));
}
