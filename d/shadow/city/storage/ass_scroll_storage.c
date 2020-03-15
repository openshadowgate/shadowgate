#include <std.h>
#include "/d/common/common.h"
inherit "/std/room";

void create() {
    ::create();
    set_property("no teleport",1);
    set_exits( (["up" : "/d/shadow/city/room/assassinscrolls"]) );
}

void reset() {
    int i;
    object scroll;

    for (i = 0; i < 13; i++)
        if(!present("parchment "+i))
            new("/d/tharis/obj/parchment")->move(TO);
    for (i = 0; i < 100; i++)
        if(!present("scroll "+i))
        {
            scroll = new("/d/magic/safe_scroll");
            scroll->move(TO);
            scroll->set_spell(random(9)+1);
        }
}
