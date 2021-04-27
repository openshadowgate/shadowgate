#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain("barren");
    set_travel("paved road");
    set_name("Fire Walk");
    set_short("%^BOLD%^%^RED%^Fire Walk%^RESET%^");
    set_long("%^RESET%^%^RED%^As you attempt to discover if a river of fire "
"will hurt by stepping into it, something wonderous and unexpected happens... "
"you are walking on fire and though you can feel the heat more than at the bank "
"of the river, you are not being burned alive... yet.");
    set_smell("default","You smell fire and brimstone.  Ash and your own hair starting to singe.");
    set_listen("default","The violent roar of rushing lava is almost deafening.");

    set_exits(([
      "portal" : ROOMS"foyer",
    ]));
}
