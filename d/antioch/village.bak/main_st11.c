//  Created by Ignatius, for ShadowGate
//  Coded  24 June, 1995
//  Antioch Area
//  Just south of the mansion

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default","The sounds of the town square fade toward the south.");
  set_smell("default","You sniff out a guardsman to the north.");
  set("short","Road to the Tower");
  set_long(
@ANTIOCH
Directly to your north you see the %^BOLD%^Dark Tower%^RESET%^ reach high above you.
This must be the great tower of Ignatius.  You see guard standing 
out in front of the doors.  To the south, the town square beckons.
ANTIOCH
  );
  set("night long",
@ANTIOCH
A large spire casts a shadow down this road, making it difficult to
see much of anything.  You note that the spire is to the north.
ANTIOCH
  );
  set_exits( ([
    "north":  VIL + "e1",
    "south":  VIL + "main_st10"
  ]) );
  set_items( ([
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({MON+"guard",MON+"philosopher"}),65,2);
}
