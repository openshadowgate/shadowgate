#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["northwest": RPATH "m22",
	            "southeast": RPATH "m24",
    ]));
}