#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "m4",
	            "northwest": RPATH "m6",
	            "north": RPATH "m12",
    ]));
}