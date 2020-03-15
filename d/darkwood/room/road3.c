#include <std.h>

inherit "/d/darkwood/room/road2";

void create()
{
    ::create();
    set_exits( ([
        "north" : "/d/darkwood/room/road2",
        "south" : "/d/darkwood/room/road4",
    ]) );
}

