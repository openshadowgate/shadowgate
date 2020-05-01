#include "/d/shadow/mon/melnmarn.h"
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
    if (!present("cuban")) {
        new("/d/common/obj/misc/cuban")->move(this_object());
    }
    if (!present("turkish")) {
        new("/d/common/obj/misc/turkish")->move(this_object());
    }
    if (!present("brazil")) {
        new("/d/common/obj/misc/brazil")->move(this_object());
    }
    if (!present("latakia")) {
        new("/d/common/obj/misc/latakia")->move(this_object());
    }
    if (!present("broadleaf")) {
        new("/d/common/obj/misc/broadleaf")->move(this_object());
    }
    if (!present("broadleaf")) {
        new("/d/common/obj/misc/broadleaf")->move(this_object());
    }
    if (!present("turkish")) {
        new("/d/common/obj/misc/turkish")->move(this_object());
    }
    if (!present("afgan")) {
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
