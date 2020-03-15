//  Created by Ignatius, for ShadowGate
//  Creates 26 June, 1995
//  Garrison Area
//  Jailer Guard Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "Another Jail Guards Room");
  set("long",
      "  This room seems to be a passageway.  It looks as though it "
      "is designed to trap people between the room north and the room "
      "south, perhaps to control their movement.\n"
      "  Two imposing looking doors are set into the north and south "
      "walls.\n"
     );
  set_items( ([
    "walls":
      "Not much special here.  You do notice some scratches on the east wall.",
    ({"scratches", "east wall"}):
      "These appear to make out some words.  Perhaps you can read them?" 
    ]) );
  set_exits( ([
    "south":GAR+"jailerrm3",
    "north":GAR+"jailerrm1"
    ]) );
  set_smell (
"default", "You smell old, putrid food and other, less appealing smells.\n"
    );
  set_listen (
    "default", "You here footsteps in the distance.\n"
    );
  set_door("portal",GAR+"jailerrm1","north","jail key");
  set_door("door",GAR+"jailerrm3","south","jail key");
  set_string("portal", "open",
             "The door swings open.  You shiver as a blast of cold air "
             "rushes over your body.\n"
            );
  set_string("door", "open","With a pull, you open the door.\n");
}

void init() {
  ::init();
  add_action("read_markings", "read");
  tell_room(GAR+"jailerrm2","%^GREEN%^The door slams shut, locking you in!\n");
  set_locked("portal",1);
  set_open("portal",0);
  set_locked("door",1);
  set_open("door",0);
  (GAR+"jailerrm1")->set_open("portal",0);
  (GAR+"jailerrm1")->set_locked("portal",1);
  (GAR+"jailerrm3")->set_open("door",0);
  (GAR+"jailerrm3")->set_locked("door",1);
}

int read_markings(string str) {
  if(!str) {
    notify_fail("What would you like to read?\n");
    return 0;
  }
  if(str!="scratches"){
    notify_fail("You can't read that!!!\n");
    return 0;
  }
  message("my_action",
    "You squint to try to make sense of the scratchings on the wall, and "
    "read the following:\n"
    " \n"
    "  Here I stand, prepared for my fate,\n"
    "  Alone in my sorrow, consumed by my hate,\n"
    "  Perhaps I would change, it really doesn't matter,\n"
    "  For I am off to see the Judge, and\n"
    " \n"
    "The message seems to end suddenly.",
    this_player());
  message("other_action",
    this_player()->query_cap_name()+" reads something.\n",
    environment(this_player()), this_player());
  return 1;
}
