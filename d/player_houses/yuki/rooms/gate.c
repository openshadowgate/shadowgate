#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^BOLD%^A giant open gate stands behind you"+
    " as the only entrance in and out of the fortress.%^RESET%^.\n");
   set_exits(([
      "south" : "/d/dagger/road/road3",
      "north" : ROOMS"c1",
   ]));






}
