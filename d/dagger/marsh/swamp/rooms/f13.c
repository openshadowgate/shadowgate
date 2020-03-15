#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits((["southeast": RPATH "f12",
                "south": RPATH "f42",
      ]));
}
