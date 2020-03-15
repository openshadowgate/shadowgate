#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["east": RPATH "f10",
                "north": RPATH "f42",
      ]));
}
