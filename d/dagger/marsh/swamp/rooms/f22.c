#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["north": RPATH "f21",
	            "south": RPATH "f1",
    ]));
}
