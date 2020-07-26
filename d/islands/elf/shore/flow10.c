#include <std.h>
#include "../elf.h"
inherit INH"flow";

void create(){
   ::create();
   set_exits(([ "south": ROOMS"shore/flow11", 
   "east": ROOMS"shore/flow5", 

     ]));

}