#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["northeast": RPATH "m20",
	            "east": RPATH "m22",
	            "northwest": RPATH "m28",
	            "west": RPATH "m45",
    ]));
}
