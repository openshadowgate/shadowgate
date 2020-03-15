#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["west": RPATH "m20",
                "east": RPATH "m52",
    ]));
}
