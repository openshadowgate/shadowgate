#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "northeast": RPATH "f39",
                "west": RPATH "f15",
      ]));
}
