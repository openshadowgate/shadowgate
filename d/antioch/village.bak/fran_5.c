#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default","You keep your eyes peeled for something interesting.");
  set_listen("default","Your acute hearing picks up the sounds of people going about their daily business.");
  set_short("Francis Street");
  set_long(
@ANTIOCH
You are standing in a small street.  To the north you spot a door that
leads into a greyish brick house.  You probably shouldn't enter the 
house, for you never know what might lurk inside.
ANTIOCH
  );
  set_exits( ([
    "enter":VIL+"house",
    "west": VIL+"main_st5"
  ]) );
  set_items( ([
    ]) );
}
