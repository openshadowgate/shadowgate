//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Soldier's Barracks");
    set_long(
    "%^ORANGE%^"+
    "This is the the barracks where the guards of the castle take their rest.  You can see "+
    "ten sets of bunkbeds in the room. At the head and foot of each bed is a large locked "+
    "chest. There is a fireplace built into the eastern wall and some firewood stacked up "+
    "next to it. A large barrel sits in the northwest corner. You hear snoring from one of "+
    "the northern beds. The two closest beds against southern wall seem to be unused.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","It smells like weapon oil and dirty socks in here.");
    set_listen("default","You hear snoring.");
    set_items(([
    	({"chests","chest"}):"They are locked, but I would not get your hopes up, Melic "+
    		"does not pay the guards that well."
	]));

    set_door("east room door",MROOMS+"meldh1","west","mithril key");
    set_door_description("east room door","The door is wooden, much as you would expect.");
    set_string("east room door","open","You open the door into the castle hallway.\n");

    set_exits(([
	"west" :MROOMS+"meldh1"
    ]));
}
