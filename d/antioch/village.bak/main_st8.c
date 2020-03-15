//  Created by Ignatius, for ShadowGate
//  Coded foo February, 1995
//  Village of Antioch
//  Town Square 2

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","Oh, happy day, you find not a thing.");
  set_smell("default","The scent of fear fills the air.");
set_listen("default","You smell rotten corpses.");
  set("short","Town Square");
  set_long(
@ANTIOCH
You have entered what at least used to be the town square.  Many 
undead people walk around now looking for food.  The smell of undead 
is greater here than in other parts of the village.
ANTIOCH
  );
  set_exits( ([
    "south":VIL+"main_st7",
    "east":VIL+"town_sq1e",
    "west":VIL+"town_sq1w",
    "north":VIL+"main_st8a"
    ]) );
  set_items( ([
    ]) );
}

void init(){
     ::init();
  do_random_encounters(({MON+"villager",MON+"merchant",MON+"zombie"}),60,3);
}
