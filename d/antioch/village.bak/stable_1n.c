//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Antioch Area

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "You hear the gentle snuffle of animals."
  );
  set_smell("default",
    "The smell here reminds you of horse manure.  Then again, it IS horse "
    "manure..."
  );
  set("short",
      "Horse stables"
     );
  set("long",
      " \n"
      "  You're standing where many of the horses feed through the day.  You "
      "see heaps and heaps of hay, oats and apples laying on the floor.\n"
      "  Occasionally a horse walks up and looks at you, but most ignore you "
      "in favor of eating their meal.\n"
      );
  set("night long",
    "  You trip into a bale of hay.\n"
     );
  set_exits( ([
 ///"north"  :"/d/antioch/island/gate_1.c",
    "south": VIL+"stable"
    ]) );
  set_items( ([
    "hay":
       "You see heaps of hay around here.\n",
    "oats":
       "The oats are old and yucky.\n",
    "apples":
       "Most of these apples were old years ago.\n"
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({
  MON+"pony"
    }), 80, 3);
}
