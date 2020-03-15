//  Created by Demonforce, For ShadowGate
//  Coded  24 June, 1995
//  Antioch Area
//  Road to the Mansion

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default","You hear some type of activity to the north.");
  set_smell("default","You delicate senses detect a fire burning to the north.");
  set("short","Road to the Tower");
  set_long(
@ANTIOCH
You are walking up a wide clean street.  Every so often you see large
statues depicting famous members of the village standing erect by well
maintained trees and flowers.  This street continues to the north and the south.  You note a large
spire to the north.
ANTIOCH
  );
  set("night long",
@ANTIOCH
The %^BOLD%^Tower%^RESET%^ casts a shadow down this road, making it difficult to 
see much of anything.  It reaches high above the street to the north.
ANTIOCH
  );
  set_exits( ([
    "north":  VIL + "main_st11",
    "south":  VIL + "main_st9"
    ]) );
  set_items( ([
    "street":"The street is quite clean.\n",
    "spire":"The spire is large and seems to be made of stone.\n",
    "statues":"the statues are all of one person: Ignatius.\n"
  ]) );
}

void init() {
  ::init();
  do_random_encounters( ({MON+"guard",MON+"merchant"}),90,1);
}
