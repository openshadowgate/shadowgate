// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no castle",1);
  set("short",
"Inside a sewer"
  );
  set_long(
@ANTIOCH
You are below the surface of the village of Antioch.
You are walking through about 6 inches of water in the sewers 
of Antioch.  This section of the sewers is lit through the grate
in the ceiling.  There is a ladder climbing back up into the town streets.
ANTIOCH
);
  set_exits(([
    "north":PIT+"pit4",
    "south":PIT+"pit6",
    "west":PIT+"pit2",
    "up":VIL+"main_st6"
]));
}

void init(){
  ::init();
}
