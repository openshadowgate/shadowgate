#include <std.h>
inherit "/std/obj/fence_store_high";

void reset() {
   ::reset();
   if(!present("lantern")) new("/d/common/obj/misc/beacon.c")->move(TO);
   if(!present("smokebomb")) new("/d/tharis/obj/smokebomb")->move(TO);
}
