#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void init() {
     ::init();
do_random_encounters(({"/d/antioch/mon/skeleton.c"}),50, 6);
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
"%^BOLD%^%^BLUE%^A dim candle keeps the hall farly light.\n"
"Large skeletons guard the walls here.  For some reason the walls are "
"of great value to them.  The wall is filled with indentations of skeleton "
"warriors.  This is the resting place for dead skeleton warriors.\n"
);
     set_smell("default", "You smell wax.\n");
     set_listen("default", "You hear the candle crackle and pop.\n");
     set_exits(([
      "down":CASTLE+"castle13",
      "up":CASTLE+"castle15"
]));
     set_items(([
     ({"candle"}):
     "This is a candle which is made out of black wax.",
     ({"wall", "walls"}):
     "It looks to be filled with skeleton warriors.",
     ({"indentations", "indentation"}):
     "They are skeleton warriors.",
     ({"staircase"}):
     "It twists and turns up to a large clearence."
]));
}
int go_up(string str){
  if(present("skeleton")){
    write("The skeleton moves to block your way up the stairs.");
    return 1;
  }
  else{
    write("%^CYAN%^You continue up the staircase.\n");
    TP->move_player(CASTLE+"castle15");
    return 1;
  }
}
