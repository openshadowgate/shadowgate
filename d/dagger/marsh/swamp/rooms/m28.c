#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["east": RPATH "m27",
	            "northwest": RPATH "m29",
	            "southeast": RPATH "m21",
    ]));
}
