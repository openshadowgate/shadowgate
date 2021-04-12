#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
    direction = "south";    
   ::create();
   
   set_exits(([
    "northeast":FROAD+"14",
    "southwest":FROAD+"16",
   ]));

}
