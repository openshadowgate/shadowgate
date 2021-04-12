#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "east";
   ::create();
   set_exits(([
    "west":FROAD+"5",
    "east":FROAD+"7",
   ]));
}
