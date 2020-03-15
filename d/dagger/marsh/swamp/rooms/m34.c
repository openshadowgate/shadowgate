#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "m35",
	            "northeast": RPATH "m33",
    ]));
}