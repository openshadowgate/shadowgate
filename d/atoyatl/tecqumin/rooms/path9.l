#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "north" : ROOMS + "path8", "south": ROOMS + "step1", 
                    "west" : ROOMS + "path24", "east" : ROOMS + "path32" ]));
}
