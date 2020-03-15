//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Intersection of Main and Francis

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_listen("default","You hear people bustling about to the north.");
  set_smell("default","Your sensitive nose detects a whiff of candle smoke.");
  set_search("default","You gasp as you discover -- NOTHING!!");
  set_property("no castle", 1);
  set("short","Intersection of Main and Francis");
  set_long(
@ANTIOCH
It appears you may be at an intersection.  It's just as empty here 
as any other section of Main Street, but you note that many of the 
people are headed north to the town square.  To the east, you notice 
a house, while to the west you spot a quiet graveyard.
ANTIOCH
  );
  set_exits( ([
    "north": VIL+"main_st6",
    "south": VIL+"main_st4",
    "west": VIL+"fran_4",
    "east": VIL+"fran_5"
    ]) );
  set_post_exit_functions(({"north", "west"}), ({"go_north", "go_west"}));
  set_items( ([
    "intersection":"You are at the intersection of two packed earth streets.",
    "park":"To the west, you notice a quaint little park.",
    ({"square", "town square"}):"Far to the north, you note a village square.",
    "homes":"Looking east, you spot a series of homes."
  ]) );
}

int go_north() {
  tell_object(TP,"A rabid rat scurries across the street.  He fixes you with a baleful stare.\nYou feel as though a ghost has crossed over your grave.",TP);
  return 1;
}

int go_west() {
  tell_object(TP,"You hear the sound of a bottle breaking behind you.  The scent of ether fills the air, and the sound of chanting fills your ears.",TP);
  return 1;
}
