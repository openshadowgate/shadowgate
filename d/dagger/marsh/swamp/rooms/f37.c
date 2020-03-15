#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "west": RPATH "f20",
                "northwest": RPATH "f38",
                "east": RPATH "f35",
      ]));
}
