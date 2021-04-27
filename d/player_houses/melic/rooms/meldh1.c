//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Lower Floor Hallway");
    set_long(
    "%^GREEN%^"+
    "There are doors on either side of the hall here.  Both doors have signs on them.  The "+
    "room is plain and the only decoration is the statue of a lightly dressed human female. "+
    "The statue stands against the eastern wall and looks out of place here. Only two "+
    "torches light this room, one beside each of the doors.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The smell of food from behind the west door.");
    set_listen("default","Snoring and other sounds of people at rest can be heard from "+
    			"the east.");
    set_items(([
    	    	"statue": "The woman has long flowing hair which is the only thing covering "+
    	    		"her above the waist. Her eyes are only slightly open and she is "+
    	    		"glancing down at the shortsword that lies in her open palms.  She has a "+
			"worn skirt tied loosely about her waist.  The torn thing hardly covers "+
			"her and leaves little to the imagination.  Very nicely shaped is an "+
			"understatement for whoever stood model for this statue. Just as you "+
			"begin to wonder what this thing is doing here you notice that the sign "+
			"on the east door. This would be just the thing a bunch of soldiers "+
			"would take with them from a sacked temple, if there were no gold or gems."
	]));
	
    set_door("east room door",MROOMS+"melbar","east","mithril key");
    set_locked("east room door",0,"lock");
     (MROOMS+"melbar")->set_locked("east room door",0,"lock");
    set_door_description("east room door","Wooden and much as you would expect a door to "+
    		"be like.  A sign posted on the door reads %^BOLD%^%^WHITE%^Soldier's "+
		"Barracks%^RESET%^.");    
    set_string("east room door","open","You open the east door and see into the soldier's "+
		"barracks.\n");
			
    set_door("west room door",MROOMS+"melsup","west","mithril key");
    set_locked("west room door",0,"lock");
     (MROOMS+"melsup")->set_locked("west room door",0,"lock");
    set_door_description("west room door","Wooden and much as you would expect a door "+
    		"to be like.  A sign on this door reads %^BOLD%^%^YELLOW%^Supply "+
    		"Room%^RESET%^.");
    set_string("west room door","open","You open the west door and see into the supply "+
		"room.\n");

    set_exits(([
	"south" :MROOMS+"meld1",
	"east" :MROOMS+"melbar",
	"west" :MROOMS+"melsup"
    ]));
}
