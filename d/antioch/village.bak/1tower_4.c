//  Created by Ignatius, for ShadowGate
//  Coded 25 February, 1995
//  Village of Antioch
//  1Tower_4 - Above Room tower_4

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set("short",
    "Guard Tower - West"
     );
  set_long(
@ANTIOCH
%^BLUE%^You are at the very top of one of the guard towers.  The tower has
not been used in some time, apparently.  There is a window providing
a clear view of who enters or leaves the village.  From here you can
also see the great tower where the god Ignatius once lived.
ANTIOCH
    );
  set_exits( ([
//"east" : VIL+"questold",
    "down": VIL+"tower_4"
    ]) );
  set_items( ([
  "tower":"The tower stands threateningly just north of the village square.",
  "window":"You can %^BOLD%^look out%^RESET%^ to see who is at the gates."
    ]) );
}

void init(){
  ::init();
  add_action("look_out","look");
}

int look_out(string str){
  object *stuff;
  int i;
  if(!str || str!="out") return 0;
  stuff = all_living(find_object_or_load(VIL+"gate_1"));
  write("%^MAGENTA%^%^BOLD%^You can see the following people at the gates of Antioch:%^RESET%^\n");
  for(i=0;i<sizeof(stuff);i++){
    if(!stuff[i]->query_invis())
      write(stuff[i]->query_short());
  }
  return 1;
}
