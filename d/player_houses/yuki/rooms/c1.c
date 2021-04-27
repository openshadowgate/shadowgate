#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^The courtyard branches out. To the east you see"+
    " soldiers practicing, to the north is the inner keep, and the sounds of horses and "+
	"wagons can be heard to the west.%^RESET%^.\n");
   set_exits(([
      "south" : ROOMS"gate",
      "east" : ROOMS"c2",
	  "west" : ROOMS"c3",
	  "north" : ROOMS"h1",
   ]));
}
