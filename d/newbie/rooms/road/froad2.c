#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "north";
   ::create();
   set_exits(([
    "south":FROAD+"1",
    "northeast":FROAD+"3",
   ]));
}
