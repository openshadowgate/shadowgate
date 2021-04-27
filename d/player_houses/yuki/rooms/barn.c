#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";
inherit "/d/common/inherit/hitching_post";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^Here a large overhang "+
   "protects a series of tethers for horses. Grooms run back and "+
   "forth tending to mounts of all types.%^RESET%^.\n");
   set_exits(([
      "south" : ROOMS"c3",
   ]));
}

