// Approaching the mountain
// Thorn@ShadowGate
// 001023
// Solaren's Player House
// solaren2.c

#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
  set_property("light", 2);
  set_short("%^YELLOW%^Approaching the mountain%^RESET%^");
  set_long(
@THORN
%^YELLOW%^Approaching the mountain%^RESET%^
%^CYAN%^The sheer hills of the area and the narrow path apparently keep most
travellers outside of this area.  That is, unless they have business
with the resident of the tower, perhaps. Here you can make out that the
mountain itself has worn down by time and the elements.

Along the southern slope of the mount, a river runs through its deep-cut
channel, speeding into the sea to the east.  The steep-sided cliffs to
the ocean and the river channel make the tower at the top nearly
unreachable except for this narrow path which is here for you to make a
tiring, but not overly hazardous climb to the southeast. 
THORN
  );
  set_smell("default", "You can vaguely smell the salts of the sea on the cool breeze.");
  set_listen("default", "The muted sound of the waves float across the distance to your ears.");
  set_items(([
    "cliffs" : "You hear but not see the ocean below the great granite cliffs nearby.",
    "sea" : "You can hear the sea pounding the roots of the hills in the distance.",
    "tower" : "You can make out a high stone wall around the tower from here, but little more.",
    "path" : "Very narrow, this path seems to wind its way into the hills toward the mountain.",
  ]));
  set_exits(([
      "southeast" : "/d/player_houses/solaren/solaren3",
      "south" : "/d/player_houses/solaren/solaren1",
  ]));
}
