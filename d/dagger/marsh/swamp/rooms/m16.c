#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["west": RPATH "m17",
	            "southeast": RPATH "m15",
	            "northeast": RPATH "m1",
    ]));
}
