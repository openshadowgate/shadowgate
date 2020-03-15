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
  set_short("Inside a tunnel");
  set_long(
@ANTIOCH
This tunnel is barely large enough for you to crawl through and the dirt is
beginning to cave in.  You find yourself hoping it is not too long
before you reach the other end.  There seems to be some light coming 
from the other end of the tunnel, but it is too dark to see into
the sewers.
ANTIOCH
);
  set_exits(([
    "out":PIT+"pit7",
    "tunnel":PIT+"tunnel2"
]));
  set_smell("default","You smell the waste from the sewers.");
}
