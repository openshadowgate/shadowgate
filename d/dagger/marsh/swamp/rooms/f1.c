#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "m44",
	            "west": RPATH "f2",
	            "north": RPATH "f22",
	            "northeast": RPATH "f30",
      ]));
}
