inherit "/std/room";
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
set_light(2);
set_indoors(3);
set_short("castle.\n");
set_long(
  " \n"
"%^BOLD%^You are in Castle of Antioch!%^RESET%^\n"
"This is the Castle of Antioch.  A dark feeling runs through your body as "
"you pass through this castle.  A myth was told about a floating castle  "
"some place by the Village of Antioch.  This castle is ruled by the same "
"vile creature who rules the village.  Unusual smells surround this room, "

"causing you to be sick.\n"
);
set_smell("default", "You smell a flower.\n");
set_exits( ([
  "north":CASTLE+"castle2",
  "down":CASTLE+"knob"
]) );
}

