// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle4.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"northwest" : "jungle7",
	
	]));
}

