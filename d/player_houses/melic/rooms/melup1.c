//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Staircase");
    set_long(
    "%^GREEN%^"+
    "The hallway is smaller up here, but still fairly large.  Both sides of the corridor "+
    "have curtains in the middle that keep the stairs half covered. The eastern stairs "+
    "lead down and the west stairs lead up. The stairs down are coverd by a long "+
    "%^RED%^red%^GREEN%^ rug. The stairs up are steep and there is no railing. To the "+
    "north you can see doors on either side of the hallway.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Only dust tickles your nose.");
    set_listen("default","You hear the wind blowing above.");
    	
    set_door("hatch",MROOMS+"melup2","up","mithril key");
    set_locked("door",0,"lock");
     (MROOMS+"melup2")->set_locked("hatch",0,"lock");
    set_door_description("hatch","The hatch is a door that covers the hole in the ceiling.");
    set_string("hatch","open","You push the hatch up to open it.  You see the sky and "+
    		"the floor of the high tower.\n");
    		
    set_exits(([
	"north" :MROOMS+"meluph1",
	"down" :MROOMS+"mel5",
	"up" :MROOMS+"melup2"
    ]));
}
