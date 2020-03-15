//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Leather Shop on Tower Road

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;


void init() {
     ::init();
do_random_encounters(({"/d/antioch/mon/bag_zombie.c"}),50, 1);
add_action("kill_zombie", "kill");
}
void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set("short",
    "A small leather goods shop"
     );
  set("long",
      " \n"
    " You enter a slightly dark room.  As you walk in, you "
"notice a very stronge smell of decay.  Looking around you see a "
"an assortment of heads, arms, legs, all kind of body parts "
"hanging on the walls here.\n"
    );
  set_exits( ([
    "south": VIL+"tower_6"
    ]) );
  set_items( ([
    ]) );
}

int kill_zombie(string str) {
 if(!present("zombie",TO)) return 0;
  if(!str || str != "zombie") return 0;
  write("%^YELLOW%^The zombie grabs you by the hand and says:%^RESET%^You
  will die in prison for your foolish actions.\n");
  TP->move_player(VIL+"jail1");
  write("%^YELLOW%^The zombie teleports you to the prison.\n");
  return 1;
}
