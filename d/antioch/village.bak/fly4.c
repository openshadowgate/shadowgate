inherit "/std/room";
#include <std.h>
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("You are on a huge eagle.\n");
     set_long(
     "\n"
"%^CYAN%^You are on a huge eagle!%^RESET%^\n"
"The eagle now is going as fast as before.  The storm is under you a little "
"bit now.  The bright %^BLUE%^blue%^RESET%^ rain showers under you, casting "
"an odd shadow from the bright brassy light from above.  The eagle suddenly "
"stops as you fall on your face.  You should leap up to the magical knob. "
"You also can hop off the eagle from here.\n"
);
     set_smell("default", "You smell the clouds.\n");
     set_listen("default", "You can hear the air running under the wings of
the eagle.\n");
}
void init() {
  ::init();
  add_action("fly","fly");
  add_action("leap", "leap");
}

int leap(string str) {
  write("%^CYAN%^You hop up to the knob.\n");
  tell_object(TO,TPQCN+" hops up to the knob.",TP);
  TP->move_player(CASTLE+"knob");
  return 1;
}

int fly(string str){
  if(str=="down"){
    write("You point the eagle toward the ground.\n");
    write("WOOOOO... The bird glides toward the ground.");
     tell_room(environment(TP),TPQCN+" flies down toward the ground.\n",TP);
    TP->move_player("/d/antioch/village/fly3");
    return 1;
  }
  if(str=="up"){
    write("You can't go any higher.\n");
    return 1;
  }
  else{
    write("Fly which way?");
    return 1;
  }
}
