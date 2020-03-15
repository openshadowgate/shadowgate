//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 1

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default","Your ears twitch at the sounds of devout prayer.");
  set_smell("default","The scent of burning candles wafts over your face.");
  set("short","Main Street in Antioch");
  set_long(
@ANTIOCH
You are travelling down a smoothly packed street that heads north
and south.  This was the main street through the village at one 
point, but now there is little activity.  You occasionally see a 
zombie move down the street, and sometimes the village guards can 
be seen.
ANTIOCH
  );
  set_exits( ([
    "south": VIL+"fount_1",
    "north": VIL+"main_st2"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters(({"/d/antioch/mon/zombie.c"}),20, 1);
}
