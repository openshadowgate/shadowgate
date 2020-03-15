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
At the top of the stairs, you find a door which you hope leads
back into town.  You think you can see daylight coming in around
the edges of the door.  This must be where the guards enter and leave
the garrison.
ANTIOCH
  );
  set_items( ([
    "walls":
      "The walls are coated with a film of water.  Small amounts of green "
      "mold are visible in the mortar.",
    "door":
      "The door is made of iron, meant to keep the citizens of Antioch "
      "from entering this place."
    ]) );
  set_exits( ([
    "down":GAR+"mainstairs",
    "out":VIL+"town_sq2w"
   ]) );
  set_pre_exit_functions(({"out"}),({"go_out"}));
  set_smell (
    "default", "The smell of rancid water and fear permeates the air.\n"
    );
  set_listen("default","You hear the sounds of the city above and the sounds of the garrison below.\n");
}

int go_out(){
  tell_player(this_player(),"You open the door and exit the garrison.\n");
  return 1;
}
