#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "m12",
	            "east": RPATH "m14",
    ]));
}