#include "/d/antioch/areadefs.h"
inherit "/std/room";

void init() {
     ::init();
add_action("grab", "grab");
}

void reset(){
  ::reset();
  if(!present("lastria"))
    new(MON+"lastria")->move(this_object());
}
void create() {
     ::create();
     set_light(2);
     set_indoors(4);
     set_no_steal(3);
     set_short("You are in the chaimber of Lastria.\n");
     set_long(
     "\n"
"You are in the Great Chamber of Lastria, the Dark Queen.  She sits on a huge "
"bed, whispering a small poem.  The candles here are dim, causing the room "
"to be very dark.  A table stands in the corner of the room, on it, is a bright "
"yellow rose.\n"
);
     set_smell("default", "You smell a rose.\n");
     set_listen("default", "You can hear a bird singing.\n");
     set_exits(([
      "south":  CASTLE+"castle21"
]));
     set_items(([
({"flower", "yellow flower"}):
"It is a bright yellow flower, maybe you could grab it."
]));
}

int grab(string str) {
write("You grab the flower, as it vanishes into thin air.\n");
return 1;
}
