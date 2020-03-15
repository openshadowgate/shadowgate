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
The tunnel slopes sharply upward to the south, and you can see a
narrow stream of waste flowing from that direction.  The water 
here is only about 3 inches deep, but you can already feel your feet
beginning to stick to the floor.
ANTIOCH
);
  set_exits(([
    "north":PIT+"pit9",
    "south":PIT+"pit7"
]));
}

void init(){
  ::init();
}
