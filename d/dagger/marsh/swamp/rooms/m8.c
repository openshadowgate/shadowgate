#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "m7",
	            "southwest": RPATH "m9",
	            "west": RPATH "m48",
    ]));
}
