#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "f12",
	            "north": RPATH "f15",
	            "southeast": RPATH "f23",
      ]));
}
