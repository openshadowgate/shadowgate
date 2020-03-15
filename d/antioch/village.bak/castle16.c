#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void init() {
  ::init();
  add_action("go_up","up");
}
void create() {
  ::create();
  set_light(1);
  set_indoors(1);
  set_short("Staircase");
  set_long(
@ANTIOCH
%^BOLD%^You are in the Castle of Antioch!
%^BOLD%^%^BLUE%^A dim candle keeps the hall farly light.  It is lighter
here, for you are reaching the top of the staircase.  As you walk on,
the stairs creak and crack beneath your feet.
ANTIOCH
  );
  set_smell("default", "You smell the candle wax and the rain.");
  set_listen("default", "You hear the candle crackle and pop.");
  set_exits(([
    "down":CASTLE+"castle15",
    "up":CASTLE+"castle17"
  ]));
  set_items(([
    "candle":"This is a candle which is made out of black wax.",
    "stairs":"They are about to crack.",
    ({"wall", "walls"}):"They appear to be damp with the rain.",
    ({"indentations", "indentation"}):"They are the remains of skeleton warriors.",
    "staircase":"It twists and turns up to a large clearing."
  ]));
}

int go_up(string str){
  write("%^CYAN%^You continue up the staircase.\n");
  TP->move_player(CASTLE+"castle17");
  return 1;
}
