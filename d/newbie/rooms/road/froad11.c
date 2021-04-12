#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
    direction = "west";
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail meets another well-trodden %^ORANGE%^path%^RESET%^%^GREEN%^ "+
   "in front of a large %^BOLD%^%^BLACK%^keep%^RESET%^%^GREEN%^ directly northwest or continues eastward.%^RESET%^");
   set_exits(([
    "northwest":KEEP"path4",
    "east":FROAD+"10",
   ]));
}
