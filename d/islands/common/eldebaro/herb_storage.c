#include <std.h>
#include "area_stuff.h"
inherit ROOM;

void create() {
    ::create();
    set_property("no teleport",1);
    set_light(3);
    set_indoors(1);
    set_name("Seneca Herb Storage");
    set_short("Seneca Herb Storage");
    set_long("This is a storage room filled with all sorts of herbs.  You
shouldn't be here!");
    set_exits(([
       "up" : ELROOMS+"herb_shop",
    ]));
}

void reset() {
    ::reset();
   while(!present("packet of herbs 78"))
new("/d/common/obj/brewing/herb_inherit")->move(TO);
   if(!present("herb pouch"))
new("/d/common/obj/brewing/herb_pouch")->move(TO);
   if(!present("herb pouch 2"))
new("/d/common/obj/brewing/herb_pouch")->move(TO);
   if(!present("herb pouch 3") && !random(3))
new("/d/common/obj/brewing/herb_pouch")->move(TO);
}
