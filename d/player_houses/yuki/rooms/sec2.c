#include <std.h>
#include "../yuki.h"

inherit STORAGE"secret.c";

void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The tunnel splits here. "+
   "To the east is a small study "+
   "room, and to the north you hear strange whispers.\n");
   set_exits(([
      "south" : ROOMS"sec1",
      "north" : ROOMS"summon",
	  "east" : ROOMS"scry",

   ]));
}
