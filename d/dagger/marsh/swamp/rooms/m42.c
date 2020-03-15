#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["east": RPATH "m41",
	            "northwest": RPATH "m44",
	            "north": RPATH "m43",
    ]));
}
