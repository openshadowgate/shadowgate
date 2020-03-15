//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Main Street - 3

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default","You hear praying to the east");
  set_smell("default","You can smell rotting food from the abandoned shop.");
  set_search("default","My, aren't we adventurous.  Nothing here, sorry.");
  set("short","Main Street in Antioch");
  set_long(
@ANTIOCH
You stand outside two shops.  To the east, you see an old wooden door.
Above it, you spot a sign with a holy symbol upon it.  Toward the west 
you notice old wooden barrels and carts filled with dried food, which 
fill the streets with a unwanted aroma.
ANTIOCH
  );
  set_exits( ([
    "south": VIL+"main_st2",
    "west": VIL+"rat_shop",
    "east": VIL+"temple",
    "north": VIL+"main_st4"
    ]) );
  set_items( ([
    ({"door", "old door", "wooden door", "old wooden door"}):
      "The door, which stands open, leads to the east.",
    ({"sign", "holy symbol"}):
      "Above the old wooden door is a sign with a holy symbol painted on "
      "it.  You admire the quality of the sign, but find it to be out of "
      "place for this area.",
    ({"barrels", "wooden barrels", "barrel"}):
      "These barrels once held all sorts of neat stuff.  Not any more..."
    ]) );
}
