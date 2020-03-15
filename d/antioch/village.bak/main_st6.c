//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 6

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default","You can just make out the sound of running water beneath you.");
  set_smell("default","The grate under your feet is releasing some really nasty smells.");
  set_search("default","You peer around the area to no avail.");
  set("short","North along Main Street in Antioch");
  set_long(
@ANTIOCH
You are walking down a wide street that leads to the north and south.
Many citizens walk here, causing quite a bit of congestion.  On the 
ground, you notice a small grate, perhaps used for sewage control.
To the north, you can make out the village square.
ANTIOCH
    );
  set_exits( ([
    "south": VIL+"main_st5",
    "north": VIL+"main_st7"
    ]) );
  set_items( ([
    ({"grate", "small grate"}):"The grate under your feet has holes wide enough to lead under the village itself.  What could be down there?",
    "street":"The village street is made of packed earth.",
    ({"square", "village square"}):"To the north, you note a bazaar area."
    ]) );
}

void init() {
  ::init();
  add_action("lift_grate","lift");
}

int lift_grate(string str){
  if(!str){
    notify_fail("Lift what?");
    return(0);
  }
  if(str!="grate"){
    notify_fail("You can't lift that!");
    return(0);
  }
  tell_room(TO,TPQCN+" lifts the grate.",TP);
  tell_player(TP,"You find stairs leading down into the sewers.\n");
  TO->add_exit(PIT+"pit5","down");
  return(1);
}

void reset(){
  ::reset();
  remove_exit("down");
}
