#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["southwest": RPATH "f9",
	            "northeast": RPATH "f7",
	            "north": RPATH "f10",
      ]));
}
