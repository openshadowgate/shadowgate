#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["west": RPATH "m21",
                "southeast": RPATH "m23",
                "north": RPATH "m20",
    ]));
}
