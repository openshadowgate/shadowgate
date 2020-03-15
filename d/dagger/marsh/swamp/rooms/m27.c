#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["east": RPATH "m20",
	            "west": RPATH "m28",
    ]));
}