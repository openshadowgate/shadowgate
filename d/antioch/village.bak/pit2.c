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
As you move away from the center, there is less and less light.
The water you are walking in is getting deeper and harder to move
through.  
ANTIOCH
);
  set_exits(([
    "south":PIT+"pit1",
    "east":PIT+"pit5"
]));
}

void init(){
  ::init();
}
