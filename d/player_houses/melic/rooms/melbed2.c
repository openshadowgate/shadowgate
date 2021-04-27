//Coded by Diego//
//add wine//

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
    "A large double-bed stands against the south wall here. The bed has "+
    "%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^ silk covers, and thick fur blankets lie at "+
    "the end of the bed.  A large fireplace is set in the north wall. There is a small "+
    "fire burning in it and servants keep the pile of firewood stocked next to it. The "+
    "floor is coverd by several rugs with different patterns. A painting is hanging on the "+
    "west wall. There is a beautifully carved sign above the bed and several dozen fresh "+
    "%^RED%^red%^CYAN%^ roses in a vase atop the fireplace.  There are small tables on "+
    "each side of the bed with bowls of fresh %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^.  "+
    "In the northwest corner there is a small cabinet.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells slightly of roses.");
    set_listen("default","The only sound is the fire burning.");
    set_items(([
    	"painting":"%^RESET%^The painting depicts and ancient %^GREEN%^forest%^RESET%^.  "+
    		"Trees grown tall with age stand as guardians throughout the%^ORANGE%^ "+
		"wood%^RESET%^ with their branches spiraling upwards reaching for the "+
		"%^BOLD%^%^CYAN%^sky%^RESET%^.  Light %^BOLD%^%^GREEN%^green%^RESET%^ leaves "+
		"cover the canopy of the %^GREEN%^forest%^RESET%^ and every ancient tree is in "+
		"full leaf.  It looks to be about mid-spring in this beautiful painting.  There "+
		"are no animals in the picture, only trees and underbrush.",
	"cabinet":"Within the cabinet there are clean towels, silk covers and furs.  There "+
		"are, also, a few drinking glasses and a bottle of wine inside.",
	"sign":"The sign reads:\n"+
		"%^GREEN%^Where you lay your head is home,\n"+
		"%^GREEN%^Where you wake the adventure starts,\n"+
		"%^GREEN%^Where you die someone else goes on.%^RESET%^\n"
	]));
	
    set_door("west room door",MROOMS+"meluph1","east","mithril key");
    set_door_description("west room door","The door is wooden, much as you would expect.");
    set_string("west room door","open","You open the door into the castle hallway.\n");
    
    set_exits(([
	"east" :MROOMS+"meluph1"
    ]));
}
