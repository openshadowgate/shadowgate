//  Created by Ignatius, for ShadowGate
//  Coded 23 June, 1995
//  Village of Antioch
//  Town Square area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("training",1);
  set_property("no castle", 1);
  set_search("default","You look all around, but find little.");
  set_smell("default","The smell here is one of the denizens of the great village.");
  set_listen("default","You slap yourself silly for trying to listen in a busy area.");
  set("short","Antioch Town Square");
  set_long(
@ANTIOCH
You can almost picture the town square full of people either trying 
to look for a good bargain or haggling for a good price.  It is quiet
here, but you begin to hear voices... it is so noisy that you can 
hardly hear yourself think.  You think there must be pickpockets 
running around in this busy area.  You check your pursestrings, find 
all is secure, and then realize what you are doing... maybe this place
is beginning to get to you.
ANTIOCH
  );
  set_exits( ([
    "north":VIL+"town_sq2e",
    "west":VIL+"main_st8"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters(({MON+"villager",MON+"shopper",MON+"merchant"}),50,3);
}
