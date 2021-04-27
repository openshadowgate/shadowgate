//Ryzan and Aunuit's House
#include <std.h>
#include "aunuit.h"

inherit ROOMS"tunnel01";

void create(){
   ::create();
   set_exits(([
   "east":ROOMS"tunnel206",
   "west":ROOMS"tunnel208",
   ]));
}
