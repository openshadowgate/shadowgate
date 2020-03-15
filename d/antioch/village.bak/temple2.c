//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Healer's Temple

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

int found = 0;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle",1);
  set("short",    "Healer's Temple"     );
  set_long(
@ANTIOCH
%^GREEN%^As you walk into this small room, you develop an incredible
feeling of peace.  In the center of this room is a small pool
of water, formed in the shape of a cross.  A silver haired old
man stands close by the pool, and looks toward you.  Behind him,
you see water flowing into the pool from a fountain.  For just an
instant, you could have sworn the man had a halo above his head.
ANTIOCH
);
  set_exits( ([
    "west": VIL+"temple"
    ]) );
  set_items( ([
    "fountain":"The water is very clear... almost too clear for this town!",
    "pool":"You wonder where the water is coming from.",
    "water":"You see no source, yet the pool is full and the fountain is flowing."
    ]) );
}

void init() {
  ::init();
}

void reset(){
  ::reset();
  if(!present("healer"))
    new(MON+"healer")->move(this_object());
  found = 0;
}
