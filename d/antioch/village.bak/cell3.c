//  Created by Ignatius, for ShadowGate
//  Coded 26 June, 1995
//  Garrison Area
//  One of the Jail Cells

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 0);
  set("short", "A jail cell");
  set("long",
      "  This cell seems to have not been used for quite some time.  The "
      "walls look to have been recently cleaned and the straw looks a bit "
      "more well kept as it lies on the floor.\n"
      "From the looks of things, the previous occupant of this cell "
      "managed to escape.\n"
      );
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.  They look to have been recently cleansed "
      "off all debris.",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "been used yet.",
    "door":
      "This door is set into the north wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "hole":PIT+"tunnel2",
    "north": GAR+"jailhall7"
   ]) );
  set_smell("default","You smell fresh dirt and straw.");
  set_listen("default","You hear footsteps.");
  set_door("cell door", GAR+"jailhall7", "north",
           "jail key");
  set_string("cell door", "open",
             "With a loud squeal from the hinges, the door swings open.\n"
            );
}
