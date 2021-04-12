#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "east";
   ::create();
   set_exits(([
    "west":FROAD+"4",
    "east":FROAD+"6",
   ]));
}
