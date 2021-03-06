#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("An island beach");
  set_long(
@VETRI
%^ORANGE%^You walk along the beach, the ocean on one side of you and a
dense jungle on the other. As you carefully step your way
over the hot sand and rocks, you wonder if that sound you
heard from the jungle was just your imagination. In the distance,
toward the center of the island, you see a mountain rise
above the trees.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the waves crashing on the beach and the trees moving in the wind... You hope.");
  set_exits(([
    "south":I_BEACH+"beach16",
    "north":I_BEACH+"beach14"
  ]));
}
