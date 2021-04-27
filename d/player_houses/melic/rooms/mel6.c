//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Castle Hallway");
    set_long(
    "%^GREEN%^"+
    "The hallway is rather empty here except for the door in the west wall.  There is a "+
    "cross on the door and the door lacks any visible locks.  The walls are plain stone "+
    "and you can now see the huge smooth blocks of stone as they were before something "+
    "melted them together on the outside.  Torches are placed at regular intervals along "+
    "the corridor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","There is a faint smell of incense in the air.");
    set_listen("default","It is silent.");
    	
    set_door("door",MROOMS+"mela","west","mithril key");
    set_locked("door",0,"lock");
     (MROOMS+"mela")->set_locked("door",0,"lock");
    set_door_description("door","A normal %^ORANGE%^wooden%^RESET%^ door with a holy "+
    	"symbol carved with great care into the wood.");
    set_string("door","open","The door swings open.  A %^BOLD%^%^WHITE%^cloud%^RESET%^ "+
    		"of incense puffs out to greet you.\n");
    		
    set_exits(([
	"north" :MROOMS+"mel7",
	"south" :MROOMS+"mel5",
	"west" :MROOMS+"mela"
    ]));
}
