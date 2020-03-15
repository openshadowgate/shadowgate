#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["northwest": RPATH "f19",
	            "southeast": RPATH "f21",
	            "east": RPATH "f37",
    ]));
}
