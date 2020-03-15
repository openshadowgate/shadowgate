#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "m48",
	            "southwest": RPATH "f32",
	            "northwest": RPATH "f34",
      ]));
}
