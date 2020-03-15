#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["south": RPATH "m1",
	            "northeast": RPATH "m3",
    ]));
}