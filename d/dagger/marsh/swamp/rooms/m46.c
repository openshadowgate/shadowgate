#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["northeast": RPATH "m45",
                "east": RPATH "m47",
    ]));
}
