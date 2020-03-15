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
      "  You are now deep in the heart of the prison area.  To your south "
      "is yet another cell that may hold unspeakable terrors.\n"
      "  The floor here is pitted and marked from years of water damage "
      "and certainly years of use.  An oil lamp is locked inside a cage "
      "in the north wall, and casts odd, disturbing shadows throughout "
      "this area.\n"
      "  You do not feel safe here, nor do you feel comfortable.\n"
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
    "door":
      "This door is set into the south wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "east": GAR+"jailhall2",
    "west": GAR+"jailhall4",
    "south": GAR+"cell4"
   ]) );
  set_smell (
    "default", "The smell of rotted flesh and human waste fills the air.\n"
    );
  set_listen (
    "default", "You hear someone moaning, maybe through the south door.\n"
    );
  set_door("cell door", GAR+"cell4", "south",
           "jail key");
  set_string("cell door", "open",
             "With a tug, the doors opens.  The hall is filled with thick "
             "smoke and the scent of bile.  You retch.\n"
            );
}

void reset() {
  ::reset();
  set_open("cell door", 0);
  set_locked("cell door", 1);
  (GAR+"cell4")->set_open("cell door", 1);
  (GAR+"cell4")->set_locked("cell door", 0);
}

