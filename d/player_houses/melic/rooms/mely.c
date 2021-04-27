//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
    set_short("Castle Yard");
    set_long(
    "%^ORANGE%^"+
    "You are now in front of the entrance door to the castle proper.  Next to the door "+
    "an old, battle-scarred half-elf sits dozing off in his chair.  Behind him a halberd "+
    "stands against the wall.  A guard dog lies at the feet of the old man watching you "+
    "without fear or threat.  To the west are stables and to the east you can see a "+
    "%^BOLD%^%^GREEN%^garden%^RESET%^.\n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","You smell fresh, clean air inter-mixed with the smells of the "+
    		"stables.");
    set_listen("default","You can hear an occassional snore from the old man.");
    set_items(([
	"halberd":"The halberd is old and has seen much use, but still seems to be in "+
		"good condition."
	]));
	
    set_door("door",MROOMS+"mel4","north","mithril key");
    set_locked("door",0,"lock");
     (MROOMS+"mel4")->set_locked("door",0,"lock");
    set_door_description("door","This door leads into the castle.  It is approximately "+
    	"10 feet tall and made of wood.");
    set_lock_description("door","lock","The lock is set into a brass plate and "+
    	"is decorated with fancy engravings.  The lock adds class and style to the "+
    	"entrance to the castle.");
    set_string("door","open","The door opens into the castle.\n");
    
    new(MMONS+"oldhalfelf")->move(TO);
    set_exits(([
	"north":MROOMS+"mel4",
	"south":MROOMS+"mel2",
	"east" :MROOMS+"mel3",
	"west" :MROOMS+"mels"
    ]));
}
