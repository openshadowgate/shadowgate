#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["northwest": RPATH "f20",
                "south": RPATH "f22",
                "west": RPATH "f46",
    ]));
}
