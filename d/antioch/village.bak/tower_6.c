//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Tower Road - 6

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

int done;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_smell("default",
    "The smell of fresh leather fills the air."
  );
  set_listen("default",
    "You hear someone working to the north."
  );
  set_search("default",
    "You look around carefully, but find nothing of value."
  );
  set("short",
    "Tower Road, outside a shop"
     );
  set_long(
@ANTIOCH
You continue your walk down this small, narrow street.  To the north,
you spy a large tower jetting towards the clouds.  Sounds of walking fill
the room as voices fill your head.  You see footprints in the dirt.
ANTIOCH
  );
  set_exits( ([
"east": VIL+"q3",
    "west": VIL+"tower_5",
    "north": VIL+"bag_shop"
    ]) );
  set_items( ([
({"dirt", "footprints", "footprint",}):
"The dirt looks very strange and feels very lumpy.  What is in there?",
  ({"street", "narrow streeet"}):
    "The street is narrow and constricting.",
  "tower":
    "The tower juts toward heaven.",
  ({"shop", "small shop"}):
    "A small shop lies to the north."
    ]) );
}

void reset(){
  ::reset();
  done = 0;
  }

void init() {
  ::init();
add_action("search_dirt", "search");
}
int search_dirt(string str) {
  int i, j;
  if(!str || str!="dirt") return 0;
  write("You pick some dirt up and look it over.");
  tell_room(TO,TPQCN+" looks at the dirt.",TP);
  if(done){
    write("You find nothing in the dirt.");
    return 1;
  }
  i = random(5);
  for(j=0;j<i;j++){
    new("/d/antioch/mon/zombie.c")->move(TO);
    new("/d/antioch/mon/zombie_guard.c")->move(TO);
  }
  write("%^YELLOW%^An army of undead arrives from the shadows.");
  done = 1;
  return 1;
}
