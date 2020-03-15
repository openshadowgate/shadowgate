#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["northeast": RPATH "f33",
	            "south": RPATH "f31",
      ]));
}
