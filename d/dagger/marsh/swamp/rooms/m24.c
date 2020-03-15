#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["northwest": RPATH "m23",
	            "south": RPATH "m25",
    ]));
}