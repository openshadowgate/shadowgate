//  Created by Ignatius, for ShadowGate
//  Coded 26 June, 1995
//  Garrison Area
//  One of the Jail Cells

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "A jail cell");
  set_long(
@ANTIOCH
The cells in the garrison are becoming less and less pleasant,
the longer you stay around.  The rock walls are damp and cold,
and you can feel yourself growing ill as you stand here.
ANTIOCH
);
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.\n",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "been cleaned in years!",
    "pillow":
      "This straw filled sack seems to act as a pillow in this hovel.  ",
    "door":
      "This door is set into the north wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "north": GAR+"jailhall1"
   ]) );
  set_smell("default","You smell the dampness in the air.");
  set_door("cell door", GAR+"jailhall1", "north",
           "jail key");
  set_string("cell door", "open",
             "The door swings open.  You shiver as a blast of cold air "
             "rushes over your body.\n"
            );
}

void init() {
  ::init();
  add_action("pry_the_paper","pry");
}

int pry_the_paper(string str) {
  if(!str){
    notify_fail("What are you trying to pry?\n");
    return 0;
  }
  if(str != "the paper") {
    notify_fail("Use your damn participles!!!\n");
    return 0;
  }
  message("my_action",
      "You try to pry the piece of paper out of the crack, and find that "
      "it is not a piece of paper!  Instead, you yank out a pissed looking "
      "bat!\n",
      this_player());
  message("other_action",
      "You watch as "+this_player()->query_cap_name()+" pulls a bat "
      "from a small crack in the wall!",
      environment(this_player()), this_player());
  return 1;
}
