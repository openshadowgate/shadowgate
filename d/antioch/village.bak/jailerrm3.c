//  Created by Ignatius, for ShadowGate
//  Created 26 June, 1995
//  Garrison Area
//  Jailer Guard Area


#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "Jail Guard Room");
  set("long",
      "  The entire west wall of the room is a grate made of steel bars. "
     "To the north, you can see a large portal with a barred window."
      " There is a large desk in the middle of the room."
      "  This area seems to be designed to hold people against their will.\n"
     );
  set_exits( ([
    "north":GAR+"jailerrm2",
    "west": GAR+"jailhall5"
     ]) );
  set_items( ([
    "walls":
      "These walls are made of solid rock.  They look very old.",
    "grate":
      "The west wall is made of a grate.  You can hear some noises coming "
      "from down the hall that is visible through the grate.",
   "desk":
     "The desk itself is cleared of all things and looks to have been recently cleaned."
    ]) );
  set_smell (
    "default", "You smell old, putrid food and another, less appealing smell.\n"
    );
  set_listen (
    "default", "You hear someone moaning, perhaps to the west.\n"
    );
  set_door("door",GAR+"jailerrm2","north","guard key");
  set_door("grate",GAR+"jailhall5","west","guard key");
  set_string("grate", "open",
             "With a squeal of protest, the grate swings open!\n"
            );
  set_string("door","open","With a pull, you open the door.\n");
  set_open("grate", 0);
  set_locked("grate", 1);
    (GAR+"jailhall5")->set_open("grate",0);
  (GAR+"jailhall5")->set_locked("grate",1);
}
