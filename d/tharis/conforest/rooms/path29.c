#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_search("default","There appears to be an overgrown path twisting %^BOLD%^%^CYAN%^north%^RESET%^ through the forest here.");
  set_exits(
    ([
    "east" : ROOMS+"path30",
    "west" : ROOMS+"path28",
    "north": "/d/player_houses/rheyn/sapling" //spot where rheyn wants sapling grove
    ]) );
    set_invis_exits(({"north"}));
}
