#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "north";
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into the town of %^BOLD%^%^ORANGE%^Offestry%^RESET%^%^GREEN%^ directly "+
   "south of here or continues northward.%^RESET%^");
   set_exits(([
    "south":MAINTOWN"nstreet3",
    "north":FROAD+"2",
   ]));
}
