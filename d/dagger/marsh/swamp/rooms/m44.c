#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();

    set_long(""+ ::query_long() + "\n%^RED%^To the northwest, the marsh grows much "
        "darker and thicker. You are fairly sure that the Marsh of Fear begins here.%^RESET%^");

    set_listen("default","You sense something extremely evil to the northwest.");

    set_exits((["southeast": RPATH "m42",
                "northwest": RPATH "f1",
                "west": RPATH "m49",
    ]));
}
