#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^Here a large overhang protects "+
   "cargo laced and secured. The entrance to the soldier's quarters is "+
   "here as well.%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"c3",
   ]));
}

void reset(){
    ::reset();
   if(!present("crow")){new(MOBS"crow_soldier.c")->move(TO);}
}
