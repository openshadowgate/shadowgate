#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["northeast": RPATH "m34",
                //"enter" : "/realms/fizbane/avatar/temple1.c",
    ]));
}