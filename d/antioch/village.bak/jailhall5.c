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
  set_property("light", 0);
  set("short", "In the jail proper");
  set("long",
      "  You are in a narrow, cramped hallway in the basement of the "
      "garrison.  To your south is a large door made of solid-looking "
      "wood.  The hallway continues to the west, and there is another "
      "door-like grate to your east.\n"
      "  Overall, the room exudes a feeling of claustropobia and fright. "
      "You wish to be away from this place.\n"
      );
  set_items( ([
    "walls":
      "The walls are coated with a film of water.  Small amounts of green "
      "mold are visible in the mortar.",
    ({"pools", "water"}):
      "Pools of brackish water are visible on the floor.  From the generally "
      "pitted condition of the floor, you're sure they've ben here for "
      "quite some time.",
    "door":
      "This door is set into the south wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed.  It appears to be a cell door.",
    "grate":
      "This grate keeps anyone from this area from entering the room "
     "directly to the east."
    ]) );
  set_exits( ([
    "east": GAR+"jailerrm3",
    "west": GAR+"jailhall6",
    "south": GAR+"cell7"
   ]) );
  set_smell( 
    "default", "You can smell incense burning in the distance.\n"
    );
  set_listen( 
    "default", "You hear someone moaning, maybe through the south door.\n"
    );
  set_door("cell door", GAR+"cell7", "south","jail key");
  set_door("grate", GAR+"jailerrm3", "east","guard key");
  set_string("cell door", "open",
             "With a groan, the door swings open.  A blast of vile smelling "
             "air comes from the room to the south.  It smells like someone "
             "spent LOTS of time in there.\n"
            );

  set_open("cell door", 0);
  set_locked("cell door", 1);
  (GAR+"cell7")->set_locked("cell door", 1);
   (GAR+"cell7")->set_open("cell door",1);
}

void reset(){
  ::reset();
  if(!present("guard"))
    new(MON+"gguard2")->move(this_object());
}
