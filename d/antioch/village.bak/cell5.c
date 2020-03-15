//  Code created by Ignatius, for ShadowGate
//  Coded 26 June, 1995
//  Garrison Area
//  One of the Jail Cells

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "A jail cell");
  set("long",
      "  You find yourself in one of the most horrible rooms imaginable.  "
      "The walls are made of a dirty rock, and are smeared with what looks "
      "like dung.  The floor is covered with dirty straw that seems "
      "designed to act as a latrine as well as a carpet.  Even the ceiling "
      "is coated with all manner of excrement.\n"
      "  The room itself resembles a cube with claustrophobic six foot "
      "sides.  You find it hard to believe that anyone could lay down here, "
      "let alone sleep.\n"
      "  A filthy pillow lays in the far corner of the room.  It seems that "
      "is the only comfort, such as it is, for anyone unlucky enough to be "
      "interred here.\n"
      );
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.  They are covered with dung and other vile "
      "bodily fluids.",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "pitted condition of the floor, you're sure they've ben here for "
      "quite some time.",
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
    "north":GAR+"jailhall6"
   ]) );
  set_listen (
    "default", "You hear someone breathing heavily!\n"
    );
  set_door("cell door",GAR+"jailhall6","north","jail key");
  set_string("cell door", "open",
             "The door swings open.  You shiver as a blast of cold air "
             "rushes over your body.\n"
            );
}

void reset(){
  ::reset();
  if(!present("prisoner"))
    new(MON+"prisoner")->move(this_object());
}
