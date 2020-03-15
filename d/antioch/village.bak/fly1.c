inherit "/std/room";
#include "/d/antioch/areadefs.h"
#include <std.h>

void create() {
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("You are on a huge eagle.\n");
     set_long(
     "\n"
"%^CYAN%^You are on a huge eagle!%^RESET%^\n"
"The eagle seems to be going faster and faster by the second.  The clouds "
"swing past your head as you continue up towards the floating castle.  You "
"see other people mounted on eagles trying to reach the floating castle, "
"but you feel as if you are on one of the more stable and powerful eagles. "
"You can not go down but only hop off of your eagle.  Yet you can fly up "
"towards the shadowy castle.\n"
);
     set_smell("default", "You smell the clouds.\n");
set_listen("default", "You can hear the air running under the wings of the eagle.\n");
}
void init() {
  ::init();
  add_action("fly","fly");
}

int fly(string str) {
  if(str=="up"){
    write("You point up towards the castle.\n");
    write("%^CYAN%^WOOOOO.. The bird glides up.\n");
    tell_room(environment(TP),TPQCN+" flies up toward the clouds.\n",TP);
    TP->move_player(VIL+"fly2");
    return 1;
  }
  if(str=="down"){
    write("You point the eagle toward the ground.\n");
    write("%^CYAN%^WOOOOO.. The bird glides down.\n");
    tell_room(environment(TP),TPQCN+" flies down toward the ground.\n",TP);
    TP->move_player(VIL+"q3");
    return 1;
  }
  else{
    write("Fly which way?\n");
    return 1;
  }
}
