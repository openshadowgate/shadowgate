//  Code created by Ignatius, for ShadowGate
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
  set_short("Stairs leading up from the garrison");
  set_long(
@ANTIOCH
You are climbing the stairs back to the town of Antioch.  You are 
very grateful to be out of that disgusting place known as
the garrison.  The guards seemed to wonder why you were walking
around -- be happy that they did not put you in one of the vacant cells!
ANTIOCH
  );
  set_items( ([
    "walls":
      "The walls are coated with a film of water.  Small amounts of green "
      "mold are visible in the mortar.",
    "door":
    "The door is set at the foot of the stairs.  It is obviously meant"
    " to keep the prisoners in the jail and citizens out."
    ]) );
  set_exits( ([
    "up":GAR+"mainstairs2",
  "south":GAR+"jailerrm1"
   ]) );
  set_smell (
    "default", "The smell of rancid water and fear permeates the air.\n"
    );
  set_listen("default","You hear the sounds of the city above and the sounds of the garrison below.\n");
  set_door("door",GAR+"jailerrm1","south","jail key");
  set_string("door","open","The door to the garrison slowly opens before you.\n");
}
