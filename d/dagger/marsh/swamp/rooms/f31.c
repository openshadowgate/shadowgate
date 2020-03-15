#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["west": RPATH "f30",
	            "east": RPATH "m11",
	            "north": RPATH "f32",
      ]));
}
