


#include "/d/antioch/areadefs.h"
inherit "/std/room";

void create() {
     ::create();
     set_light(1);
     set_indoors(3);
     set_short("snakes");
     set_long(
     "\n"
"Snakes fill the room.  The snakes look fearsome yet do not bother you "
"and stay far from you.\n"
);
}
void init(){
    ::init();
    do_random_encounters(({MON+"copperhead",MON+"cottonmouth",MON+"cobra",MON+"kcobra",MON+"python",MON+"rattlesnake"}),50,10);
}

void reset(){
  ::reset();
  if(!present("demon"))
    new(MON+"qdemon")->move(this_object());
remove_exit("out");
}
