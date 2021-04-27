//Ryzan and Aunuit's House
#include <std.h>
#include "aunuit.h"

inherit ROOMS"tunnel01";

void create(){
   ::create();
   set_exits(([
   "northeast":ROOMS"tunnel200",
   "west":ROOMS"tunnel202",
   ]));
}
