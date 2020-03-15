#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "m29",
	            "west": RPATH "m37",
	            "north": RPATH "m50",
    ]));
}
