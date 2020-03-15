//  Created by Ignatius, for ShadowGate
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
      "  Standing inside this room, you are overcome with panic.  The walls "
      "and the ceiling are covered with large metal spikes, some of which "
      "are decidedly NOT clean.\n"
      "  The room is about six feet on a side, and the ceiling is a low, "
      "dark affair.  You wonder how anyone could stay sane in this room, "
      "but feel strongly that you don't want to find out.\n"
      );
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.  Large metal spikes poke from the walls, "
      "making this room even smaller than it appears!",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "been cleaned in ages.",
    "ceiling":
      "The ceiling, much like the walls, looks to have been hewn from the "
      "living rock.  It has been thoughtfully covered in crap.\n"
      "Large spikes poke down from above, forcing you to stoop.\n",
    "door":
      "This door is set into the north wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "north": GAR+"jailhall2"
   ]) );
  set_listen (
    "default", "You hear footsteps in the distance.\n"
    );
  set_door("cell door", GAR+"jailhall2", "north",
           "jail key");
  set_string("cell door", "open",
             "With a loud squeal from the hinges, the door swings open.\n"
            );
}

void reset(){
  ::reset();
  if(!present("prisoner"))
    new(MON+"prisoner2")->move(this_object());
}
