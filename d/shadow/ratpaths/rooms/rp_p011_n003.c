#include <std.h>
#include "common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " Path south is blocked with massive metal gates shut close.");
    set_exits(([
                   "north":PATH+"rp_p011_n002",
                   ]));

}
