#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "west";    
   
   ::create();
   set_exits(([
    "east":FROAD+"9",
    "west":FROAD+"11",
   ]));
}
