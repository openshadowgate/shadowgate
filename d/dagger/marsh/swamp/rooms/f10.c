#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["south": RPATH "f8",
	            "west": RPATH "f11",
	            "north": RPATH "f12",
      ]));
}
