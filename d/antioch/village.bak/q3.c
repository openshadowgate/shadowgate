//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Tower Road - 7

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short",
    "Tower Road, West end of Town"
     );
  set("long",
      " \n"
    "  You now stand outside a granite wall which surrounds the tower.  "
    "There is a great deal of brush and foliage here, which makes it "
    "hard to inspect the area.  You don't see any visible openings, so "
    "this must be a dead end.\n"
    );
  set_exits( ([
    "west": VIL+"tower_6.c"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters(({"/d/antioch/mon/eagle1.c"}),75,1);
}
