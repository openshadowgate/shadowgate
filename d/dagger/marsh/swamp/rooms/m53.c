#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
                   "northeast": RPATH "m15",
                   "southwest": RPATH "m52",
    ]));
}
