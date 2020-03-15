#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG;

void create() {
  ::create();

  set_exits( ([ "north" : ROOMS + "zig12" ,
                "south" : ROOMS + "zig17"]) );


	set_climb_exits(([
		"climb":({ROOMS+"zig20",3,6,300}),
		"descend":({ROOMS+"zig01",5,18,100}),
	]));

}
