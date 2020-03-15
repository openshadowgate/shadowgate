#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["west": RPATH "m18",
	            "east": RPATH "m16",
    ]));
}