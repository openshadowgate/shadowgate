//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Village of Antioch
//  Tower Road - 3

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short",
    "Tower Road, East end of Town"
     );
  set_long(
@ANTIOCH
You stare at the village wall as it bends around the road.  Here there is
but one way back, and that is the way you came.  Oddly, leaving seems to be
an appealing thought.  Nothing here but dead plants and creatures eating
what they can to survive.
ANTIOCH
  );
  set_exits( ([
    "east": VIL+"tower_4"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
}
