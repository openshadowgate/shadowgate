#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"shore/shore7", 
     "west": ROOMS"shore/shore5",

     ]));

}
