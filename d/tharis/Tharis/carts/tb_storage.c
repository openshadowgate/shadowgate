#include <std.h>
inherit ROOM;
void create()
{
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "tobacco vendor's cart");
    set("long", "Supplies and such are stored here.\n");
}

void reset()
{
    ::reset();
    if (!present("pirate's booty tobacco")) {
        new("/d/common/obj/misc/cuban")->move(this_object());
    }
    if (!present("white dragon tobacco")) {
        new("/d/common/obj/misc/turkish")->move(this_object());
    }
    if (!present("tsarven tobacco")) {
        new("/d/common/obj/misc/brazil")->move(this_object());
    }
    if (!present("hafling's homeblend tobacco")) {
        new("/d/common/obj/misc/latakia")->move(this_object());
    }
    if (!present("dwarf's pride tobacco")) {
        new("/d/common/obj/misc/broadleaf")->move(this_object());
    }
    if (!present("luxury of tharis tobacco")) {
        new("/d/common/obj/misc/afgan")->move(this_object());
    }
    if (!present("pipe")) {
        new("/d/common/obj/misc/pipe")->move(this_object());
    }
}

void call_reset()
{
    reset();
}
