#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " Path to the east is blocked with massive metal gates.");
    set_exits(([
    "west":PATH+"rp_p036_p016",

                   ]));

}
