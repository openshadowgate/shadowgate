#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["northeast": RPATH "m8",
	            "southwest": RPATH "m10",
	            "west": RPATH "m11",
    ]));
}