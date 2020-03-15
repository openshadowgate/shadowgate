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
"The eagle seems to be getting quiet tired and loses speed.  You remain "
"at a good one hundred miles per hour.  The eagle seems to be getting too "
"high and your ears hurt.  A huge storm has developed, rain rushes down  "
"from the clouds above and below you.  The eagle seems to be worried about"
"the storm and tucks his head under its arm.  As the rain slashes against "
"your face you feel a great pain for it is now hailing.  You also can't "
"hop off here because of the rain and lightning.  The only way is straight "
"up.\n"
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
    TP->move_player(VIL+"fly4");
    return 1;
  }
  if(str=="down"){
    write("You point the eagle toward the ground.\n");
    write("WOOOOO... The bird glides down.\n");
     tell_room(environment(TP),TPQCN+" flies down toward the ground.\n",TP);
    TP->move_player(VIL+"fly2");
    return 1;
  }
  else{
    write("Fly which way?");
    return 1;
  }
}
