//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Tower Road - 5

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_smell("default",
    "The scent of fear permeates the air."
  );
  set_listen("default",
    "You can hear movement in the tower above you, you think."
  );
  set_search("default",
    "There is nothing of worth anywhere in this village!  Get out!!!"
  );
  set("short",
      "Tower Road, near the Fountain"
     );
  set_long(
@ANTIOCH
You are walking down a narrow street.  Above you looms a guard tower,
so large that it casts a dark shadow along much of the road.  The
sound of laughter fills the streets and echos far into the shadows.
The road continues to the east and west.
ANTIOCH
  );
  set_exits( ([
    "up": VIL+"1tower_5",
    "west": VIL+"fount_1",
    "east": VIL+"tower_6"
  ]));
  set_post_exit_functions(
    ({"east", "west"}), ({"go_east", "go_west"})
  );
  set_items( ([
    ({"tower", "guard tower"}):"The tower looms overhead, blocking the sun."
    ]) );
}

void init() {
  ::init();
}

int go_west() {
    message("my_action",
            "A silky voice fills your head:\n  Get out while you still "
            "can, you poor fool.\n",
            TP);
}

int go_east() {
  message("my_action",
          "You sense people watching you!\n",
          TP);
}
