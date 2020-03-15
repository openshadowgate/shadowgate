#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["northwest": RPATH "m41",
	            "east": RPATH "m17",
	            "southwest": RPATH "m19",
    ]));
}
