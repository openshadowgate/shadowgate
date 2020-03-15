//Octothorpe (1/17/12)
//Shadow, Shadow Way 5

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"shadway4",
      "east" : ROOMS"westcross",
   ]));
}