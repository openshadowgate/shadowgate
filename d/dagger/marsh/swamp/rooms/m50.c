#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["northeast": RPATH "m49",
                "south": RPATH "m36",
    ]));
}
