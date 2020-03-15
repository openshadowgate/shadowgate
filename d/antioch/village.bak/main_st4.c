//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 4

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "The wind whistles through the village, chilling your bones."
  );
  set_smell("default",
    "To the north, you smell raw sewage..."
  );
  set_search("default",
    "Sorry, not much here..."
  );
  set("short",
    "Along The Main Street of Antioch"
     );
  set("long",
@ANTIOCH
You are walking along a street made of smooth, hard packed earth.
The road is fairly empty, and you see few signs of normal life here.
Occassionally, a guardsman passes through to check for trouble, and
you are wondering where all the villagers are.
ANTIOCH
    );
  set_exits( ([
    "north": VIL+"main_st5",
    "south": VIL+"main_st3"
    ]) );
  set_items( ([
    ({"street", "road"}):
      "The road is made of packed earth."
    ]) );
}

void init() {
  ::init();
}



