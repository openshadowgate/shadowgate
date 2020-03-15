//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 7

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","Main Street in Antioch");
  set_long(
@ANTIOCH
You stand outside a bar.  To the northeast appears to be a store.
To the west you see a large set of swinging doors.  Above the doors 
hangs a sign with a picture of a mug of ale.  Beside the doors lie
several drunks, sleeping off their stupor.
ANTIOCH
  );
  set_exits( ([
    "west":VIL+"bar",
    "south": VIL+"main_st6",
    "north": VIL+"main_st8"
    ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
    do_random_encounters(({MON+"drunk2"}),60,5);
}
