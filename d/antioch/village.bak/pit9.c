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
The water is flowing down toward the western branch of the sewers.
You can almost see the bottom of the tunnel here... if you wanted to look 
closely enough, that is!
ANTIOCH
);
  set_listen("default","The rushing water sounds more distant here.");
  set_exits(([
    "west":PIT+"pit4",
    "south":PIT+"pit8"
]));
}

void init(){
  ::init();
}
