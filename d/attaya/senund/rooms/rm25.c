#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "west" : ROOMS+"rm16",
        "east" : ROOMS+"rm26"
   
    ]) );

}

 