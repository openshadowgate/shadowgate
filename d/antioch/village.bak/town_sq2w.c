//  Created by Ignatius, for ShadowGate
//  Coded 23 June, 1995
//  Village of Antioch
//  Part of the Town Square

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","You find a great bargain her, but little else.");
  set_smell("default","You smell a good deal here.  A very good deal....");
  set_listen("default","You ears pick up the sounds of coin changing hands.");
  set("short","Town Square of Antioch");
  set_long(
@ANTIOCH
You are well into the town square here.  The scents of cooking food
and the sounds of money changing hands fills your head.  Roast lamb,
chicken, hot breads and other morsels were once served hereabouts.
The village prison is to the west, but you cannot enter it.
ANTIOCH
  );
  set_exits( ([
    "south" :VIL+"town_sq1w",
    "east":VIL+"main_st8a"
  ]) );
  set_items( ([
    ]) );
}
