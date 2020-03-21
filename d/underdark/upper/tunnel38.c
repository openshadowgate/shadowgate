#include <std.h>
#include "../defs.h"
inherit INH + "spiderarches";

void create()
{
    ::create();
    set_long("" + ::query_long() + "\n");
    set_exits(([
                   "southwest" : UPPER "tunnel37",
                   "southeast" : UPPER "tunnel35",
               ]));
}

void reset()
{
    ::reset();
    if (!present("altar")) {
        new("realms/odin/ashra_altar")->move(this_object());
    }
}
