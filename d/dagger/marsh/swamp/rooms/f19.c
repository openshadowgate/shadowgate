#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["west": RPATH "f18",
	            "southeast": RPATH "f20",
                "south": RPATH "f48",
    ]));
}
