#include "/d/shadow/room/city/melnmarn.h"
#include "/d/antioch/areadefs.h"
#include <daemons.h>

inherit ROOM;

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Antioch's Genral Store");
  set_long(
@ANTIOCH
%^CYAN%^You look around the store peering at the wonderous gold and silver 
objects that stand on the shelves.  The one thing you do not understand
is why an orc is the shopkeeper.  You can <buy> or <sell> items here,
but you might not want to trust the shopkeeper.
ANTIOCH
);

  set_items(
    (["shop" : "A general store, actually.",
    "store" : "A place where you can buy and sell stuff.",
    "counter" : "An worn and battered oak counter. About waist high.",
    "shelves" : "The shelves are made of oak."]) );
  set_exits(([
    "east"  : VIL+"main_st9"
  ]));
  set_property("no castle", 1);
  set_smell("default","The smell of oil lanterns, and rope fills your nostrils.");
  set_listen("default","The sounds of a craftmans tools, fill your ears.");
}

void init(){
  ::init();
  if(!present("orc",TO))
    new(MON+"orc")->move(TO);
}
