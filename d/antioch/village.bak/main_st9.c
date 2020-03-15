//  Created by Ignatius, for ShadowGate
//  Coded 23 June, 1995
//  Village of Antioch
//  Main Street - 9

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","You look around, but find only broken dreams.\n");
  set_listen("default","You hear the sound of people shouting far to the north.\nThey are shouting: WE LOVE IGNATIUS.\n");
  set("short","Road to the Tower");
  set_long(
@ANTIOCH
You are walking on a clean wide street made of carefully crafted 
stone blocks.  Large stone statues line the street, providing a 
Gothic feel to the area.  Manicured trees and flowers stand on the 
grassy areas of the road, which continues north and south.  There 
is some sort of store off to the west.
ANTIOCH
  );
  set_exits( ([
    "south":VIL+"main_st8a",
    "west":VIL+"vil_store",
    "north":VIL+"main_st10"
  ]) );
  set_items( ([
    "statues":"They look like they are starting to fall apart.",
    "flowers":"They are beginning to wilt.",
    "trees":"They are dying, like the rest of the village, with nobody to look after them."
    ]) );
}

