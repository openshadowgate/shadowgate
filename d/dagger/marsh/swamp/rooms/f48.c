#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "south": RPATH "f47",
                "north": RPATH "f19",
      ]));
}
