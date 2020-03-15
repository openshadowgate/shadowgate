#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["southeast":"/d/dagger/marsh/path8",
	            "north": RPATH "m2",
	            "southwest": RPATH "m16",
    ]));
}
