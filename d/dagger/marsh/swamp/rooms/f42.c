#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "north": RPATH "f13",
                "south": RPATH "f11",
                "west": RPATH "f43",
      ]));
}
