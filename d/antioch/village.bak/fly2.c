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
"You continue up through the clouds.  Your hair flies back as your lungs "
"drop a level.  Fog of silver fills the air making it hard for you to breath "
"A shadow covers the clouds here making it also very dark, yet light leeks  "
"in through the clouds.  A storm is starting.\n"
);
     set_smell("default", "You smell the clouds.\n");
     set_listen("default", "You can hear the air running under the wings of
the eagle.\n");
}
void init() {
     ::init();
  add_action("fly","fly");
}

int fly(string str){
  if(str=="up"){
    write("You point up towards the castle.\n");
    write("WOOOOO.. The bird glides up.\n");
     tell_room(environment(TP),TPQCN+" flies up toward the clouds.\n",TP);
      TP->move_player(VIL+"fly3");
    return 1;
  }
  if(str=="down"){
    write("You point the eagle toward the ground.\n");
    write("WOOOOO.. The bird glides down.\n");
     tell_room(environment(TP),TPQCN+" flies down toward the ground.\n",TP);
    TP->move_player(VIL+"fly1");
    return 1;
  }
  else{
    write("Fly which way?\n");
    return 1;
  }
}
