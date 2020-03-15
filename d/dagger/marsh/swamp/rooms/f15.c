#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["south": RPATH "f14",
	            "southeast": RPATH "f16",
	            "east": RPATH "f40",
    ]));
}
