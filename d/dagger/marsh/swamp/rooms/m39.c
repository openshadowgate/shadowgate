#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southeast": RPATH "m38",
	            "west": RPATH "m40",
    ]));
}