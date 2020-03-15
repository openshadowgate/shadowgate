//  Code created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Garrison Area
//  One of the Jail Cells

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 1);
  set("short", "A jail cell");
  set("long",
      "  This cell seems to have not been used for quite some time.  The "
      "walls look to have been recently cleaned and the straw looks a bit "
      "more well kept as it lies on the floor.\n"
      "  Perhaps this cell is waiting for a new resident.\n"
      );
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.  They look to have been recently cleansed "
      "off all debris.",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "been used yet.",
    "ceiling":
      "The ceiling, much like the walls, looks to have been hewn from the "
      "living rock.  It has been thoughtfully covered in crap.\n"
      "Isn't that pleasant?",
    "door":
      "This door is set into the north wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "north": GAR+"jailhall3"
   ]) );
  set_listen(
    "default", "You hear footsteps in the distance.\n"
    );
  set_door("cell door", GAR+"jailhall3", "north",
           "jail key");
  set_string("cell door", "open",
             "With a loud squeal from the hinges, the door swings open.\n"
            );
}
