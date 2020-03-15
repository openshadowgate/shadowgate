//  Created by Ignatius, for ShadowGate
//  Coded 23 February, 1995
//  Village of Antioch
//  Francis Street - 4

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","You decide to inspect the area, but don't find anything useful.");
  set_smell("default","Your nose does not discern anything special.");
  set_listen("default","You hear the sounds from the town square to the northeast.");
  set_short("Near the graveyard.");
  set_long(
@ANTIOCH
You are travelling down a small dirt road going east and west.
There are many dead trees by the side of the road that bring 
much needed shade to the area.  Over to the west, you see a 
graveyard.
ANTIOCH
  );
  set_exits( ([
    "west": VIL+"fran_3",
    "east": VIL+"main_st5"
    ]) );
  set_items( ([
    ]) );
}
