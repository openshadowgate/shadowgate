//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Second Floor Hallway");
    set_long(
    "%^GREEN%^"+
    "The hallway is rather empty here, exept for the doors on either side.  Both doors have "+
    "locks on them but you guess they are meant to keep people out, not to lock anyone in. "+
    "The walls are coverd with large tapestries. The corridor is warm here and a bit more "+
    "'homey' than other parts of the castle. Lit torches line the walls.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Only a hint of dust tickles your nose.");
    set_listen("default","It is quiet and calm.");
    	
    set_door("east room door",MROOMS+"melbed1","east","mithril key");
    set_locked("east room door",0,"lock");
     (MROOMS+"melbed1")->set_locked("east room door",0,"lock");
    set_door_description("east room door","The door is wooden, much as you would expect.");
    set_string("east room door","open","You open the east door and see a bedroom.\n");
    
    set_door("west room door",MROOMS+"melbed2","west","mithril key");
    set_locked("west room door",0,"lock");
     (MROOMS+"melbed2")->set_locked("west room door",0,"lock");
    set_door_description("west room door","The door is wooden, much as you would expect.");
    set_string("west room door","open","You open the west door and see a bedroom.\n");
    
    set_exits(([
	"north" :MROOMS+"meluph2",
	"south" :MROOMS+"melup1",
	"east" :MROOMS+"melbed1",
	"west" :MROOMS+"melbed2"
    ]));
}
