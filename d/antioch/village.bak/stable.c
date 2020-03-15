//  Created by Ignatius, for ShadowGate
//  Coded 24 June, 1995
//  Antioch Area

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "You cannot hear much, the smell is too strong."
  );
  set_smell("default",
    "The smell here fills your being with visions of filth."
  );
  set("short",
      "Horse stables"
     );
  set("long",
      " \n"
    "  If you thought the smell was bad outside, you find it far worse in "
    "here!  The scent of manure and unbathed horses is overpowering, bringing "
    "water to your eyes.\n"
    "  As you cover your nose, you note that horses here are being cared for, "
    "after a fashion.\n"
      );
  set("night long",
    "  WOW, does it ever stink in here!!!\n"
     );
  set_exits( ([
    "west":  VIL + "mans_st5",
    "north":  VIL + "stable_1n",

    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({
MON+"grey"
    }), 90, 2);
}
