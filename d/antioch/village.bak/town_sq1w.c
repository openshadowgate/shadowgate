//  Created by Ignatius, for ShadowGate
//  Coded 23 June, 1995
//  Village of Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","You look all around, but find little.");
  set_smell("default","The smell here is one of the denizens of the great village.");
  set_listen("default","Alas, your ears detect little.");
  set("short","Town Square of Antioch");
  set_long(
@ANTIOCH
Once the town square was full of people either trying to look for 
a good bargain or haggling for a good price.  It's quite noisy
from all these sales, at least in your head it is.  So noisy that 
you can hardly hear yourself think.  Every so often you feel someone
bump into you, but when you look, nobody is there.
ANTIOCH
  );
  set_exits( ([
    "north": VIL+"town_sq2w",
    "east":VIL+"main_st8"
  ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters(({"/d/deku/monster/bear.c",MON+"goblin.c","/d/deku/monster/shadow.c",}),50,1);
}
