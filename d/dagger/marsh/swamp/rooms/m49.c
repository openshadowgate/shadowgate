#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["east": RPATH "m44",
                "southwest": RPATH "m50",
    ]));
}
