#include <std.h>
#include "../yuki.h"

inherit STORAGE"secret.c";

void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The tunnel ends at an alcove "+
   "you can use to return to the fortress, or head deeper into the bowels "+
   "of the fortress.\n");
   set_exits(([
      "south" : ROOMS"h3",
      "north" : ROOMS"sec2",

   ]));
}
