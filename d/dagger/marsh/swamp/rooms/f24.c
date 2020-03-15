#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["northwest" : RPATH "f23",
	            "east"      : RPATH "f25",
	            "southeast"      : RPATH "f41",
      ]));
}
