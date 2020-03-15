//  Created by Ignatius, for ShadowGate
//  Coded 26 June, 1995
//  Garrison Area
//  Part of the Jail

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "In the jail proper");
  set("long",
      "  You are in a narrow, cramped hallway in the basement of the "
      "garrison.  To your south is a large door made of solid-looking "
      "wood.  The hallway continues to the east and the west.\n"
      "  The feeling in this area is one of fear and hatred.  You can "
      "almost smell it.\n"
      );
  set_items( ([
    "walls":
      "The walls are coated with a film of water.  Small amounts of green "
      "mold are visible in the mortar.",
    ({"pools", "water"}):
      "Pools of brackish water are visible on the floor.  From the generally "
      "pitted condition of the floor, you're sure they've ben here for "
      "quite some time.",
  "mold":
    "Mold covers the walls, and turns your stomach.  It's not a pretty sight.",
  "hallway":
    "The hallway leads off in both the east and west directions.  The "
    "feeling of claustrophobia gets stronger.",
    "door":
       "This large door is set into the south door, and seems to pivot on "
       "hinges that are protected from abuse by steel plates.  You seem to "
       "feel certain that this door leads into another cell."
    ]) );
  set_exits( ([
    "east": GAR+"jailhall5",
    "west": GAR+"jailhall7",
    "south": GAR+"cell5"
   ]) );
  set_smell (
    "default", "The smell of rancid water and fear permeates the air.\n"
    );
  set_listen (
    "default", "You hear someone moaning, maybe through the south door.\n"
    );
  set_door("cell door", GAR+"cell5", "south",
           "jail key");
  set_string("cell door", "open",
             "The door swings open.  You shiver as a blast of cold air "
             "rushes over your body.\n"
            );

  set_open("cell door", 0);
  set_locked("cell door", 1);
  (GAR+"cell5")->set_open("cell door", 0);
  (GAR+"cell5")->set_locked("cell door", 1);
}

