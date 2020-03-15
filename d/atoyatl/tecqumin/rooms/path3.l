#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits((["north" : ROOMS + "path2", "east": ROOMS + "path28", "south" : ROOMS + "deadend1"]));
}

