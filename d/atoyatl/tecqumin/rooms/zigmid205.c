#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid204" ,
	          "north" : ROOMS + "zigmid206"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh103",5,6,20}),
       "descend":({ROOMS + "zigmid107",5,6,20}),
  ]));
}
