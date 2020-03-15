//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Tower Road - 4

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_short("Along Tower Road");
  set_long(
@ANTIOCH
This street is very narrow.  You feel pressed between the city walls
and the back of what seems to be some of the small village shops.
A guard tower looms overhead, and the road, such as it is, continues 
to the east and the west.
ANTIOCH
  );
  set_exits( ([
    "up": VIL+"1tower_4",
    "west": VIL+"tower_3",
    "east": VIL+"fount_1"
    ]) );
  set_items( ([
   "street":"This street is very narrow.  It must not be used very much.",
   "walls":"There is nothing very special about these walls.  Just stone with crumbling mortar.",
    "tower":"Looking up at the tall tower, you wonder briefly if it is such a good idea to explore it.  It looks evil and deadly!",
    ]) );
}

void init() {
  ::init();
}
