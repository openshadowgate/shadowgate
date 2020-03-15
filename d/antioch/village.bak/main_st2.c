//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 2

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default", "You tilt your head, and catch the scent of candles burning.");
  set_smell("default","You hear the sound of prayer in the distance.");
  set_search("default","AHA!, you cry, as you discover a mound of dirt.");
  set("short","Main Street in Antioch");
  set_long(
@ANTIOCH
You are walking down a busy street in the village of Antioch.  The 
lane is deserted now, although you can picture merchants trying to 
sell their wares to passers-by.  You spot a peaceful looking building 
to the northeast.
ANTIOCH
  );
  set_exits( ([
    "south": VIL+"main_st1",
    "north": VIL+"main_st3"
    ]) );
  set_post_exit_functions(({"north"}), ({"go_north"}));
  set_items( ([
    "building":"To the northeast is a peaceful looking building."
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({MON+"guard"}),50,1);
}

int go_north() {
  tell_player(TP,"You hear the sound of rustling cloth in the shadows.\nWhen you look, nothing is there.\n");
  tell_object(TO,TPQCN+" is hearing strange things.  Perhaps "+TP->query_subjective()+" is going crazy!", TP);
}
