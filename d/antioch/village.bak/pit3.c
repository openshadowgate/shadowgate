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
The water seems to be rushing into this part of the sewers.
The sewer continues to the northwest on a much sharper downward
slant.  The bottom is getting slippery and you are beginning
to wonder if it is wise to travel any further.  As you get farther
from where you entered the sewers, it is getting darker and darker.
ANTIOCH
);
  set_exits(([
    "northwest":PIT+"pool1",
    "east":PIT+"pit4"
]));
}

void init(){
  ::init();
}
