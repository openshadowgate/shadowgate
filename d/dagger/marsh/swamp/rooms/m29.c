#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southeast": RPATH "m28",
	            "northwest": RPATH "m36",
	            "west": RPATH "m30",
    ]));
}