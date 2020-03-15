//  Created by Ignatius, for ShadowGate
//  Coded 24 June, 1995
//  Antioch Area
//  Near the mansion stables

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "You hear stable noises near here."
  );
  set_smell("default",
    "You smell horses and other barn animals nearby."
  );
  set("short",
    "Path to stables"
     );
  set("long",
      " \n"
    "  It appears you are walking down a path that leads to the stables.  You "
    "note many horse prints on the dirt path, as well as other, less pretty, "
    "signs a horse was present.\n"
    "  Diretly to the east, you spot a small stable.  To the west is the "
    "front door of the mansion.\n"
      );
  set("night long",
    "  Your nose detects the sounds of animals to the east.\n"
     );
  set_exits( ([
"west": VIL + "e1",
    "east": VIL + "mans_st5"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
}
