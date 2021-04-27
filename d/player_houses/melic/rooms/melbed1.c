//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Bedroom");
    set_long(
    "%^CYAN%^"+
    "This room has a rug that leads from the door in the west wall, through the middle of "+
    "the room to the east wall. On either side of the rug, up against the southeast and "+
    "northeast walls, are 2 beds. The beds look well made and clean. A large window is set "+
    "in the east wall, to let the morning sun awaken any occupants. Beside each bed is a "+
    "small table with a %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^ bowl on it. The room has no "+
    "fireplace, but is still warm, especially the floor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is fresh and warm.");
    set_listen("default","You hear a faint whistling noise from below.");
    	
    set_door("east room door",MROOMS+"meluph1","west","mithril key");
    set_door_description("east room door","The door is wooden, much as you would expect.");
    set_string("east room door","open","You open the door into the castle hallway.\n");
    
    set_exits(([
	"west" :MROOMS+"meluph1"
    ]));
}
