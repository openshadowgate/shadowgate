#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"6-5",
       "east" : F_ROOMS"4-5",
       "north" : F_ROOMS"5-6",
       "south" : F_ROOMS"5-4",
       "southeast" : F_ROOMS"4-4",
       "southwest" : F_ROOMS"6-4",
       "northeast" : F_ROOMS"4-6",
       "northwest" : F_ROOMS"6-6",
    ] ));
}
