#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "up" : ROOMS"wall27",
      "south" : SEWERS"sewer14",
   ]));
}