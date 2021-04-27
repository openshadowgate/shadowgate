//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_short("Gates inside Castle Belegost");
    set_long(
    "%^ORANGE%^"+
    "You are inside the outer walls of the castle Belegost.  The massive iron gate is now "+
    "behind you.  From here you can see the castle is built out of stone that has been "+
    "melted and is totally smooth.  The walls seem to still radiate some of the heat that "+
    "formed them.  At regular intervals you see guards pass as the walk their post along "+
    "the walls.  Just north is the castle yard.\n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The smell of horses are hinted at in the wind.");
    set_listen("default","You can hear snoring coming from the north.");
    set_items(([
    	({"wall","walls"}):"The walls are about 30 feet high and look very solid.  Atop "+
    		"the walls you can see guards on patrol"
		]));
		
    set_door("gates",MROOMS+"mel1","south","mithril key");
    set_door_description("gates","The gates are massive and made of iron, they seem too "+
		"heavy to be moved by normal means.  As you look closer you notice a faint "+
		"red aura surounding the gates.");
    set_string("gates","open","%^BOLD%^%^BLUE%^The massive gates swing fully open "+
    		"without a sound.%^RESET%^\n");
		
    set_exits(([
	"north":MROOMS+"mely",
	"south":MROOMS"mel1"
    		]));
}
