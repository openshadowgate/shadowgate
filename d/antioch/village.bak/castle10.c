inherit "/std/room";
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(     
@ANTIOCH
%^BOLD%^You are in the Castle of Antioch!%^RESET%^
This place is getting stranger by the minute.  With the strange
creatures you have been seeing, you begin to wonder what has really
been going on in this village.  Every now and then, you think you can
hear a voice calling to you...
ANTIOCH
  );
  set_smell("default","You can smell the stones.");
  set_listen("default","Your every movement echoes off the stone walls.");
     set_exits(([
         "south": CASTLE+"castle9",
         "east": CASTLE+"castle11"
]));
}
void init() {
     ::init();
do_random_encounters(({
"/d/antioch/mon/incartes.c"
}),50, 1);
  add_action("go_east","east");
}

int go_east(string str){
  if(present("incartes")){
    write("Incartes will not let you pass.\n");
    return 1;
  }
}
