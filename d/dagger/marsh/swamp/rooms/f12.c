#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["south": RPATH "f10",
	            "northwest": RPATH "f13",
	            "northeast": RPATH "f14",
      ]));
}
