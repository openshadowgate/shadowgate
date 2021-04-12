#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
    direction = "south";    
   ::create();
   set_exits(([
    "north":FROAD+"12",
    "south":FROAD+"14",
   ]));
}
