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
The sewer water appears to be getting deeper as it rushes on toward
the west.  The light from the surface is dimming as you head
away from the grate.
ANTIOCH
);
  set_listen("default","You hear the rushing water.");
  set_smell("default","It is a sewer! Do you really want to know what you are smelling?");
  set_exits(([
    "west":PIT+"pit3",
    "east":PIT+"pit9",
    "south":PIT+"pit5"
]));
}

void init(){
  ::init();
}
