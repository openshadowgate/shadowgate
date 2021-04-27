//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/6/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"tunnel01";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"tunnel04",
      "east" : ROOMS"gates"
   ]));
}