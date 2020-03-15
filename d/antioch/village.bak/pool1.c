// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(-1);
  set_indoors(1);
  set_property("no castle",1);
  set("short",
"Inside a sewer"
  );
  set_long(
@ANTIOCH
You are below the surface of the village of Antioch.
You can now feel your shoes begin to stick in the sludge on the
bottom of the tunnels.  There is no light from the surface any longer
and it is very difficult to see where you are going.
ANTIOCH
);
  set_listen("default","You hear the water rushing around you.");
  set_exits(([
    "southeast":PIT+"pit3",
    "north":PIT+"pool2"
]));
}

void init(){
  ::init();
}
