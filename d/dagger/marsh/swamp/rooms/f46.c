#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "east": RPATH "f21",
                "west": RPATH "f47",
      ]));
}
