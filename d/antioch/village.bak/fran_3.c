//  Created by Ignatius, for ShadowGate
//  Coded foo February, 1995
//  Village of Antioch
//  Francis Street - 3
//  Entrance to Antioch Park

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","Your eyes scan the area for anything suspicious, but you fail to see anything interesting.");
  set_smell("default","You catch the scent of grass and trees.");
  set_short("Antioch graveyard entrance");
  set_long(
@ANTIOCH
You are standing right outside of the graveyard.  It looks as if 
it would be a very unrelaxing place, except for the odd sounds that 
come from within the graveyard confines.  The dirt road continues 
to the east.
ANTIOCH
  );
  set_exits( ([
    "enter":VIL+"graveyard",
    "east": VIL+"fran_4"
    ]) );
  set_items( ([
    ]) );
}
