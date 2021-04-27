//Ryzan and Aunuit's House
//Coded by ~Circe~ 10/4/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"shadow14",
      "east" : ROOMS"tunnel01",
      "south" : ROOMS"shadow4",
      "southeast" : ROOMS"shadow15" //Yes, it returns you to this room.
   ]));
}