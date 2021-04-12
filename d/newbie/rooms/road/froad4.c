#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "east";
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up into the town of %^BOLD%^%^ORANGE%^Offestry%^RESET%^%^GREEN%^ directly "+
   "west of here or continues eastward.%^RESET%^");
   set_exits(([
    "west":MAINTOWN"estreet3",
    "east":FROAD+"5",
   ]));
}
