#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();

    set_long(""+ ::query_long() + "\n%^RED%^To the north lies a large ruined keep. "
        "However, the moat surrounding it is quite full of slime filled water, "
        "and the keeps drawbridge is raised.%^RESET%^");

    set_exits((["south": RPATH "m42",
                "northeast": RPATH "m10",
//                    "north": RPATH "keep1.c",
    ]));

//    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
    //if(FLAG == 0)
    //{
        write("You can't go north! The drawbridge is raised!");
	    return 0;
    //}
    //return 1;
}
