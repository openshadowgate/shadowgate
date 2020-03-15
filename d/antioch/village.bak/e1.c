//  Created by DemonForce, For ShadowGate
//  Coded  24 June, 1995
//  Antioch Area

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_listen("default","You hear very little here.");
  set_short("At the base of the Tower");
  set_long(
@ANTIOCH
You are just outside the Dark Tower that you have been seeing from
throughout the village.  It is even larger than you thought it would 
be, now that you stand at the base.  From the outside, it appears to 
be the most well-maintained building in the entire village.  The 
entrance to the Tower is guarded day and night...are they here to 
keep something in, or to keep you out?
ANTIOCH
  );
  set_pre_exit_functions(({"enter"}), ({"GoThroughDoor"}));
  set_exits( ([
    "enter": VIL + "t1",
//    "east":VIL+"mans_st4",
    "south":  VIL + "main_st11"
  ]));
  set_items( ([
    ]) );
}

int GoThroughDoor(){  
  int LEVEL =TP->query_lowest_level();
  if(LEVEL < 10){
    write("You must be above level 10 to enter the tower.\n");
    return 0;
  }
  if(present("juggernaut")){
    write("The juggernaut will not let you enter the Tower.");
    return 0;
  }
  else{
    write("You may enter.\n");
    return 1;
  }
}

void reset() {
  ::reset();
  do_random_encounters(({MON+"juggernaut"}),75,4);
  if(!present("juggernaut"))
    new(MON+"juggernaut")->move(TO);
}
