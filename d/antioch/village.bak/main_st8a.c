//  Created by Ignatius, for ShadowGate
//  Coded 18 February, 1995
//  Village of Antioch
//  Main Street - 8

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","Main Street in Antioch");
  set_long(
@ANTIOCH
You are walking in the former town square of Antioch.  This part of 
town is ugly and dead, like the rest of the town.  The smell of undead 
continues to the north.
ANTIOCH
      );
  set_exits( ([
    "south":VIL+"main_st8",
    "west":VIL+"town_sq2w",
    "east":VIL+"town_sq2e",
    "north":VIL+"main_st9"
]) );
  set_items( ([
    ]) );
}

