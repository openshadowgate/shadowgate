//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Rations shop

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set("short",
    "Rations Shop"
     );
  set("long",
      " \n"
    "%^ORANGE%^As you walk into this room, a breeze of pungent and spicy smells "
    "hits your face.  You see many different types of food here, all "
    "preserved in one way or another, placed on shelves or in boxes.  "
    "You see the store's counter to the west.\n"
      );
  set_exits( ([
    "west": VIL+"rat_shop2",
    "east": VIL+"main_st3"
    ]) );
  set_items( ([
    "food":"It appears that small creatures have been nibbling.",
    "shelves":"You see a rat scurry across the shelves."
    ]) );
}

void init() {
  ::init();
}
