//  Created by Ignatius, for ShadowGate
//  Created 25 June, 1995
//  Garrison Area 
//  Jailer Guard Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "The Jail Guards Room");
  set("long",
      "  This room is in a terrific state of disarray.  The desk is "
      "covered with loose papers and scraps of food, some of which looks "
      "to have spilled over onto the floor.\n"
      "  The entire west wall of the room is a grate made of steel bars. "
      "To the south, you can see a large door with a barred window.\n"
      "  This area seems to be designed to hold people against their will.\n"
     );
  set_exits( ([
    "south":GAR+"jailerrm2",
    "north":GAR+"mainstairs",
    "west": GAR+"jailhall1"
     ]) );
  set_items( ([
    "walls":
      "On the east wall you see a large lever.",
    "grate":
      "The west wall is made of a grate.  You can hear some noises coming "
      "from down the hall that is visible through the grate.",
    "lever":
      "This is a large steel lever set into the east wall.  You are unsure "
      "of its purpose."
    ]) );
  set_smell (
"default", "You smell old, putrid food and other, less appealing smells.\n"
    );
  set_listen (    "default", "You hear someone moaning, perhaps to the west.\n"    );
  set_door("door",GAR+"mainstairs","north","jail key");
  set_door("grate",GAR+"jailhall1","west","guard key");
  set_door("portal",GAR+"jailerrm2","south","guard key");
  set_string("door", "open","The door swings open.  You shiver as a blast of cold air rushes over your body.\n");
  set_string("grate", "open","With a squeal of protest, the grate swings open.\n");
  set_string("portal", "open","With a pull, you open the door.\n");
  set_open("grate", 0);
  set_locked("grate", 1);
  (GAR+"jailhall1")->set_open("grate", 0);
  (GAR+"jailhall1")->set_locked("grate", 1);
  set_open("door",0);
  set_locked("door",1);
  (GAR+"mainstairs")->set_open("door",0);
  (GAR+"mainstairs")->set_locked("door",1);
}

void init() {
  ::init();
  add_action("pull_lever", "pull");
}

int pull_lever(string str) {
  if(!str) {
    notify_fail("What would you like to pull?\n");
    return 0;
  }
  if(str != "lever") {
    notify_fail("You can't pull that!!!\n");
    return 0;
  }
  message("my_action",
    "You yank on the lever, and it comes down with a squeal.  A large "
    "door opens in the ceiling, and a huge pile of crap falls on your "
    "head!\n"
    "WOW, did that ever hurt!\n",
    this_player());
  message("other_action",
    "As "+this_player()->query_cap_name()+" pulls on the lever, you notice "
    "a large door open overhead.  You dodge out of the way as a huge pile "
    "of dung falls on "+this_player()->query_cap_name()+"'s head.\n"
    "Yuck!!\n",
    environment(this_player()), this_player());
  this_player()->add_hp(-20);
  return 1;
}
