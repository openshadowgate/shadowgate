//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
    set_short("Dark Tunnel");
    set_long(
    "%^BOLD%^%^BLACK%^"+
    "The tunnel comes to an dead end here. The walls are %^RESET%^%^ORANGE%^dirt "+
    "%^BOLD%^%^BLACK%^rather than mountain stone here and the ceiling is supported by "+
    "%^RESET%^%^ORANGE%^wooden %^BOLD%^%^BLACK%^pillars along the walls. The draft is "+
    "stronger here, but you cannot see where it is coming from.  \n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You smell old dirt.");
    set_listen("default","You hear distant footsteps.");
    set_items(([
   	({"walls","wall"}):"Amazingly, you haven't been buried alive yet!",
   	"ceiling":"The ceiling is rough and uneven, except for the flat square of the "+
   		"trapdoor above the middle of the room."
	]));
	
    set_door("trapdoor",MROOMS+"melpit","up","mithril key");
    set_door_description("trapdoor","The trapdoor is a door that covers the hole in the "+
		"ceiling.");
    set_string("trapdoor","open","You push the trapdoor up to open it.  Dirt, debris and "+
		"dead vegetation rain down on you from the floor of the room above.  \n");
		
    set_exits(([
	"northeast" : MROOMS+"mel8d",
	"up" : MROOMS+"melpit"
    ]));
}
