#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "f33",
	            "northwest": RPATH "f35",
	            "northeast": RPATH "f36",
      ]));
}
