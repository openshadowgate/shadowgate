#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "west" : ROOMS"ruins/ruins_8",
        "north" : ROOMS"ruins/ruins_11",
        "south" : ROOMS"ruins/ruins_5",
        ]));
}
