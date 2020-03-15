#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southeast": RPATH "m37",
	            "northwest": RPATH "m39",
    ]));
}