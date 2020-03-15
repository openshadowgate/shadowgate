inherit "/std/room";
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(
@ANTIOCH
%^BOLD%^You are in the castle of Antioch!%^RESET%^
Light shines through a huge window here, causing the castle to be
bathed in an eerie light.  You can see the village of Antioch
through the window and can sense its corruption.  At least you are
safe  here... you hope!
ANTIOCH
    );
     set_smell("default", "You can smell the stones.\n");
     set_exits(([
    "west":CASTLE+"castle7",
       "north": CASTLE+"castle9"
]));
     set_items(([
]));
}
void init() {
     ::init();
do_random_encounters(({
"/d/antioch/mon/zombie.c",
"/d/antioch/mon/skeleton.c"
}),50, 1);
  add_action("go_north","north");
}

int go_north(string str){
  if(present("zombie")){
    write("The zombie blocks your path north.\n");
    return 1;
  }
  if(present("skeleton")){
    write("The skeleton blocks you path north.\n");
    return 1;
  }
}
