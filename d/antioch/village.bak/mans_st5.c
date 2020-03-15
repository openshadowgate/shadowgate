//  Created by Ignatius, for ShadowGate
//  Coded 24 June, 1995
//  Antioch Area
//  Near the mansion stables

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "You hear stable noises near here."
  );
  set_smell("default",
    "You smell horses and other barn animals nearby."
  );
  set("short",
    "Path to stables"
     );
  set("long",
      " \n"
    "  You are directly outside the stables now.  A trough of dirty water, "
    "perhaps for the use of the animals, stands beside the doors of the "
    "stable.\n"
    "  The stable itself is made of old, warped wood.  It seems sturdy, "
    "though, at least to your eye.\n"
      );
  set("night long",
    "  Your nose detects the sounds of animals to the east.\n"
     );
  set_exits( ([
    "west":  VIL + "mans_st4",
    "east": VIL+"stable"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({
"/d/deku/monster/shadow.c"
    }), 40, 4);
}
