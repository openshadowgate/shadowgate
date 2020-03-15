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
"%^BOLD%^%^YELLOW%^A dim candle keeps the hall fairly light.\n"
"This is the begining of a large hall.  Indeed the bigest in the castle.  "
"The hall twists and turns up to a big black clearence.  This hall looks to "
"to be 50 feet tall.  A staircase is here to help you up, but be carefull "
"for some of the stairs are very old and might be dangerous.\n"
);
     set_smell("default", "You smell wax.\n");
     set_listen("default", "You hear the candle crackle and pop.\n");
     set_exits(([
       "west": CASTLE+"castle12",
       "up": CASTLE+"castle14"
]));
     set_items(([
     ({"candle"}):
     "This is a candle which is made out of black wax.",
     ({"staircase"}):
     "It twists and turns up to a large clearence."
]));
}
int go_up(string str){
  if(present("skeleton")){
    write("A skeleton blocks the way up the stairs.");
    return 1;
  }
  else{
    write("%^CYAN%^You continue up the staircase.\n");
      TP->move_player(CASTLE+"castle14");
    return 1;
  }
}


