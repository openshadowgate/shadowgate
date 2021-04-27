//Ryzan and Aunuit's House
#include <std.h>
#include "aunuit.h"

inherit ROOMS"tunnel01";

void create(){
   ::create();
   set_exits(([
   "east":"/d/player_houses/silesse/cave.c",
  "southwest" : ROOMS"tunnel201",
   ]));
}
