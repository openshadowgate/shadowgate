//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  1Tower_5 - Above Room tower_5

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short",
    "Guard Tower - East"
     );
  set("long",
@ANTIOCH
%^BLUE%^You are at the very top of one of the guard towers.  The tower has
not been used in some time, apparently.  There is a window providing
a clear view of who enters or leaves the village.  From here you can
also see the great tower where the god Ignatius once lived.
ANTIOCH
    );
  set_exits( ([
    "down": VIL+"tower_5"
    ]) );
  set_items( ([
    "window":"You can %^BOLD%^look out %^RESET%^to see who is at the gates.",
    "tower":"The tower stands threateningly just north of the village square."
    ]) );
}

void init() {
  ::init();
  add_action("down", "down");
  add_action("look_out","look");
}

int down(string str) {
write("%^MAGENTA%^A voice whispers:%^RESET%^I am watching you always.\n");
TP->move_player(VIL+"tower_5");
return 1;
}

int look_out(string str){
  object *stuff;
  int i;
  if(!str || str!="out") return 0;
  stuff = all_living(find_object_or_load(VIL+"gate_1"));
  write("%^BOLD%^%^MAGENTA%^You can see the following people at the gates of Antioch:\n");
  for(i=0;i<sizeof(stuff);i++){
    if(!stuff[i]->query_invis())
      write(stuff[i]->query_short());
  }
  return 1;
}
