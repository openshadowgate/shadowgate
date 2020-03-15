//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Small Temple

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set("short",
    "Small Temple"
     );
  set("long",
      " \n"
    "%^GREEN%^You enter a small temple.  In here, you see statues of many "
    "different gods placed along the north and south walls.  A wide "
    "variety of religious symbols mark the walls and the ceiling.  "
    "At the moment, only a handful of people are here praying.  Toward "
    "the east there is another room.\n"
      );
  set_exits( ([
    "west": VIL+"main_st3",
    "east": VIL+"temple2"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
}
