#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("grate");
     set_long(
     "\n"
"You are in a horde of spikes.\n"
"Every part of this room is a spike.  The walls seem to be getting closer "
"and closer.  One of the spikes looks like a lever.\n"
);
set_smell("default", "You smell blood.\n");
set_listen("default", "You hear the rusty walls creeping up on you.\n");
set_items(([
({"spike", "lever"}):
"Maybe you could pull it.",
  "spikes":
"They are red with blood."
]));
}
void init() {
     ::init();
add_action("pull", "pull");
}

int pull(string str) {
write("YES!\n");
write("A huge hole opens up under you.\n");
  TP->move_player(CASTLE+"snakes");
return 1;
}

