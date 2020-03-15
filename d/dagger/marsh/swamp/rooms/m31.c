#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "m32",
	            "northeast": RPATH "m30",
    ]));
}