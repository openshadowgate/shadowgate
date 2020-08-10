#include <std.h>
#include "../elf.h"
inherit INH"ruin";

void create(){
   ::create();
   set_exits(([ "north": ROOMS"shore/ruin26", 
   "south": ROOMS"shore/ruin11", 
     ]));

}