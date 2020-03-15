#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["south": RPATH "m5",
	            "northeast": RPATH "m13",
    ]));
}