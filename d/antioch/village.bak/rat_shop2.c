//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Inner Rations Shop

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set("short",
    "Rations Shop"
     );
  set_long(
@ANTIOCH
%^ORANGE%^Here you see many preserved foods laying about, many dried by the wind
of the mountains.  There are also jars of some type of pickled food
sitting on shelves.
ANTIOCH
  );
  set_exits( ([
    "east": VIL+"rat_shop"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();

do_random_encounters(({"/d/deku/monster/ogre.c"}),50,1);
}
