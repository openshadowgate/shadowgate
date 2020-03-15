#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits((["north" : RPATH "m19",
                "west" : RPATH "m27",
                "southwest" : RPATH "m21",
                "east" : RPATH "m51",
                "south" : RPATH "m22",
               ]));
}
