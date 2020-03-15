#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southeast": RPATH "m6",
	            "northwest": RPATH "m8",
                "northeast" : WITCH "rooms/archway"
    ]));
}