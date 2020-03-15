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
     set_indoors(3);
     set_short("hall");
     set_long(
     "\n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"%^BOLD%^%^GREEN%^A dim candle keeps the hall farly light.\n"
"The walls seem to be moving and twisting in the flickering candlelight, "
"and you find yourself feeling a little sick.  As you move into the "
"castle, you are beginning to wonder what all those skeleton guards "
"have been guarding."
);
  set_smell("default", "You smell the candle wax.");
     set_listen("default", "You hear the candle crackle and pop.\n");
     set_exits(([
      "down":CASTLE+"castle14",
      "up":CASTLE+"castle16"
]));
     set_items(([
     ({"candle"}):
     "This is a candle which is made out of black wax.",
     ({"wall", "walls"}):
     "As you look and touch the wall you seem to enjoy the nice smooth EYE BALLS.",
     ({"indentations", "indentation"}):
     "They are skeleton warriors.",
     ({"staircase"}):
     "It twists and turns up to a large clearence."
]));
}
int go_up(string str){
write("%^CYAN%^You continue up the staircase.\n");
  TP->move_player(CASTLE+"castle16");
return 1;
}


