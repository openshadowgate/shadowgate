// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(0);
  set_indoors(1);
  set_property("no castle",1);
  set_short("Inside a tunnel");
  set_long(
@ANTIOCH
The tunnel leads into a room here.  You wonder if it could
possibly be any worse than returning to the sewers.  You see 
that the dirt is crumbling a little more here, so you had
better decide what you are going to do soon!
ANTIOCH
);
  set_exits(([
    "tunnel":PIT+"tunnel1",
    "out":GAR+"cell3"
]));
}
