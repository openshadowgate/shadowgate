//  Code created by Ignatius, for ShadowGate
//  Coded 26 June, 1995
//  Garrison Area
//  Part of the Jail

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "std/vault";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "In the jail proper");
  set("long",
      "  You have reached the end of this hallway.  To the east, the "
      "narrow, creepy passageway leads back toward freedom, while a "
      "cell door occupies the south wall.\n"
      "  Looking over at the west wall, you notice an odd ring that "
      "looks to have been slammed into the wall.\n"
      );
  set_items( ([
    "walls":
      "The walls are coated with a film of water.  Small amounts of green "
      "mold are visible in the mortar.",
    ({"pools", "water"}):
      "Pools of brackish water are visible on the floor.  From the generally "
      "pitted condition of the floor, you're sure they've ben here for "
      "quite some time.",
    ({"lamp", "oil lamp"}):
      "This lamp is housed in a secure cage in the north wall.  The light "
      "that it gives off is a sickly color and makes you depressed.",
    "ring":
      "This ring seems to have been used to shackle prisoners.  It is very "
      "worn and old.",
    "door":
      "This door is set into the south wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "east":GAR+"jailhall7",
    "south":GAR+"cell1"
   ]) );
  set_smell (
    "default", "The smell of rancid water and fear permeates the air.\n"
    );
  set_listen (
    "default", "You hear someone moaning, maybe through the south door.\n"
    );
  set_door("cell door",GAR+"cell1","south",
           "jail key");
  set_string("cell door", "open",
             "The door swings open.  You shiver as a blast of cold air "
             "rushes over your body.\n"
            );
  set_open("cell door", 0);
  set_locked("cell door", 1);
    (GAR+"cell1")->set_open("cell door",0);
    (GAR+"cell1")->set_locked("cell door",1);
}

void reset(){
  ::reset();
  if(!present("guard"))
    new(MON+"gguard1")->move(this_object());
}
