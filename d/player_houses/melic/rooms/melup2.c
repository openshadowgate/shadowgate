//Coded by Diego//
//Put peer in so can see mel1//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_travel(PAVED_ROAD);
   set_terrain(VILLAGE);
    set_short("High Tower");
    set_long(
    "%^GREEN%^"+
    "You have reached the top of the tower. Large pillars support the wooden roof since "+
    "there are no real walls other then a 14-inch high cirle of bricks around the ledge. "+
    "From here you can see down over the castle yard, the gates and several hundred yards "+
    "off into the distance. The stairs down are coverd by a wooden hatch. The wind is "+
    "quite strong and chilly here. The mountains to the north look dark and forbidding.\n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air is fresh and cold.");
    set_listen("default","You hear only the wind.");
    	
    set_door("hatch",MROOMS+"melup1","down","mithril key");
    set_door_description("hatch","The hatch is a door that covers the hole in the floor.");
    set_string("hatch","open","You lift the hatch to open it and see a stairs "+
    		"leading downward.\n");
    		
    set_exits(([
    	"gates" : MROOMS+"mel1",
	"down" :MROOMS+"melup1"
    ]));
    set_invis_exits(({"gates"}));
    set_trap_functions(({"gates"}),({"nogo"}),({"gates"}));
}
int nogo(){
   	if(avatarp(TP)) return 1; 
    	if(interactive(TP)){
    		TP->move(MROOMS+"melup2");
   		write("What?");
	    	return 1;
    	}
}
