#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"55",
        "south" : ELROOMSD+"39",
        "west" : ELROOMSD+"53",        
    ]));
}
