//  Village of Antioch
//  Pit Area
// Coded By Blackmage

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(1);
  set_indoors(1);
  set_property("no castle", 1);
  set("short",
     "Inside a sewer"
     );
  set("long",
@ANTIOCH
It appears that you are below the surface of the village of Antioch.
It is very dark here, and there is the odd sound of water flowing
rapidly through this area.  Occasionally, you feel a cold, damp wind
blow over your face.  The tunnel slopes downward to the south.  
The walls are covered with a thick brown slime.
ANTIOCH
    );
  set_exits( ([
    "north":PIT+"pit2",
    "east":PIT+"pit6"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
}
