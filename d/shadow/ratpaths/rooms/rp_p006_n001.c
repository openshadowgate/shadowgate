#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p007_n001",
"west":PATH+"rp_p005_n001",

                   ]));

}

