#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "east": RPATH "f18",
                "southwest": RPATH "f40",
      ]));
}
