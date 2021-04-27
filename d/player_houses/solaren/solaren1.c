// Into the hills
// Thorn@ShadowGate
// 001023
// Solaren's Player House
// solaren1.c

#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
  set_property("light", 2);
  set_short("%^YELLOW%^Into the hills%^RESET%^");
  set_long(
@THORN
%^YELLOW%^Into the hills%^RESET%^
%^CYAN%^You find yourself on a narrow path that leads up into some hills
jutting out into the Dagger Sea.  To the far east, you can see an
ancient mountain, worn down by time, that rises above the cliffs and
hills.  On that hill appears to be a thin spire that reaches above the
sea mist.  Here the path turns sharply to the north, where you will lose
sight of the Dagger Sea road to the west.
THORN
  );
  set_smell("default", "You can vaguely smell the salts of the sea on the cool breeze.");
  set_listen("default", "The muted sound of the waves on the cliffs below float up to your ears.");
  set_items(([
    "cliffs" : "You can see the ocean below the great granite cliffs",
    "sea" : "You can hear the sea pounding the roots of the hills in the distance.",
    "spire" : "Definitely man-made, this appears to be a tall tower on the summit of the mountain.",
    "path" : "Very narrow, this path seems to wind its way into the hills toward the mountain.",
  ]));
  set_exits(([
    "west" : RPATH "road17",
    "north" : "/d/player_houses/solaren/solaren2",
  ]));
}
