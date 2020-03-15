inherit "/std/room";
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(     
" \n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"Light seeks in through the crack in the wall here.  You could peek through "
"the crack.  A monster is here which has 3 arms.  It seems to be a mutant "
"of some kind.  Yet its head is falling apart.\n"
);
     
     

     set_smell("default", "You can smell the stones.\n");
     set_exits(([
       "south": CASTLE+"castle8",
       "north": CASTLE+"castle10"
]));
     set_items(([
({"peek"}):
"Light seeks through this crack, the light is comming from a window.",
({"crack"}):
"Light seeks through this crack, the light is comming from a window."
]));
}
void reset(){
  ::reset();
/*
if(!present("creature"))
    new("/d/antioch/mon/3.c")->move(this_object());
*/
}

void init(){
  ::init();
  add_action("go_north","north");
}

int go_north(string str){
  if(present("creature")){
    write("The creature blocks your way north!");
    return 1;
  }
}
