#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^This area of the courtyard "+
   "is abuzz with activity as merchants move wagons and soldiers pass by. "+
   "To the north you can see what looks like a stable.%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"c1",
	  "west" : ROOMS"c4",
	  "north" : ROOMS"barn",
   ]));
}
