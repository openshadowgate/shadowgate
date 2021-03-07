#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_search("default","There appears to be an overgrown %^BOLD%^%^CYAN%^path%^RESET%^ twisting north through the forest here.");
  set_search("path","The twisting %^BOLD%^%^CYAN%^path%^RESET%^ is overgrown but passable.");
  set_exits(
    ([
    "east" : ROOMS+"path30",
    "west" : ROOMS+"path28",
    "path": "/d/player_houses/rheyn/sapling" //spot where rheyn wants sapling grove
    ]) );
    set_invis_exits(({"path"}));
}
