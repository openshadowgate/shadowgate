#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["northwest": RPATH "m16",
                "east": "/d/dagger/marsh/path7",
                "southwest": RPATH "m53",
    ]));
}
