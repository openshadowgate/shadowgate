#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"wall3",
      "west" : ROOMS"wall1",
   ]));

}