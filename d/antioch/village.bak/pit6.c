// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(1);
  set_indoors(1);
  set_property("no castle",1);
  set("short",
"Inside a sewer"
  );
  set_long(
@ANTIOCH
You are below the surface of the village of Antioch.
The bottom of the tunnel appears to slope upward here.  The water
is running out of this room in both directions.  You see light in 
the room to the north and more darkness to the west.
ANTIOCH
);
  set_exits(([
    "north":PIT+"pit5",
    "west":PIT+"pit1"
]));
}

void init(){
  ::init();
}
