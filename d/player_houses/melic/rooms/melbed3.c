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
    "A thick rug covers the whole floor in this room. A good sized bed stands against the "+
    "north wall. The bed looks very solid and could hold a very large person, it is also "+
    "clean and looks inviting. Beside the bed, on the right, is a table with a large "+
    "%^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^ bowl on it. A large window is set in the wall "+
    "just above the head of the bed. The room has no fireplace but is still warm, "+
    "especially the floor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of clean linen.");
    set_listen("default","You hear a faint whistling noise from below.");
    	
    set_door("east room door",MROOMS+"meluph2","west","mithril key");
    set_door_description("east room door","The door is wooden, much as you would expect.");
    set_string("east room door","open","You open the door into the castle hallway.\n");
    
    set_exits(([
	"west" :MROOMS+"meluph2"
    ]));
}
