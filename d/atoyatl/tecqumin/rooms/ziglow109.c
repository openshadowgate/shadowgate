#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow110" ,
	          "south" : ROOMS + "ziglow108"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow207",5,6,20})
  ]));
}
