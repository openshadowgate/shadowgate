inherit "std/room";
#include "/d/antioch/areadefs.h"

void create(){
  ::create();
  set_light(0);
  set_indoors(1);
  set_short("A house in Antioch.");
  set_long(
@ANTIOCH
%^RED%^From the appearance of this house, the owners abandoned it quite
some time ago.  The windows are covered, but with the little light
in the room, you can see that it could use some attention.  What is
left of the furniture is either broken or breaking, and some unfriendly
spirits seem to have taken over the place!
ANTIOCH
  );
  set_smell("default","You smell the dust covering everything.");
  set_listen("default","You hear the sounds of the city outside.");
  set_exits(([
    "exit":VIL+"fran_5"
  ]));
}

void init(){
  ::init();
  if(!present("ghost")&&!present("element")){
    new(MON+"ghost")->move(this_object());
    new(MON+"ghost")->move(this_object());
    new(MON+"ghost2")->move(this_object());
    new(MON+"ghost")->move(this_object());
  }
}

