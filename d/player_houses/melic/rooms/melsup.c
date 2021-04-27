//Coded by Diego//
//add food wine: a bottle of red wine, beer: a mug of beer, fewine: a glass of fewine. food: a good meal. salad: a salad meal on a plate.//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Supply Room");
    set_long(
    "%^ORANGE%^"+
    "This is a huge room, to the north you can see shelf after shelf of food supplies. "+
    "Along the southern wall barrels are lined up. Most of the barrels are marked to show "+
    "they contain water, but some hold beer. In the southwest corner there is a shelf with "+
    "wine bottles in it. There are a few lit torches placed along the walls.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You smell food.");
    set_listen("default","You hear water dripping from a leaky barrel.");
    set_items(([
    	({"shelf","shelves"}):"Many items of food and crates fill the shelves.",
    	"food":"Mostly military rations, but also some fresh food is stored here on the "+
		"shelves.",
   	"barrels":"Ordinary water and beer barrels.",
   	({"wine","bottles","bottle"}):"Most of the bottles contain red wine. A few smaller "+
                "bottles are marked 'Feywine'.",
	"crate": "An ordinary crate."
	]));
	
    set_door("west room door",MROOMS+"meldh1","east","mithril key");
    set_door_description("west room door","The door is wooden, much as you would expect.");
    set_string("west room door","open","You open the door into the castle hallway.\n");
    
    set_search("shelves","You find a few unmarked crates under the northern shelves that "+
		"dont quite fit on it. One of the crates has less dust on it like it has "+
  		"recently been moved.");
    set_search("shelf","You find a few unmarked crates under the northern shelves that "+
    		"dont quite fit it. One of the crates has less dust on it like it has recently "+
		"been moved.");
    set_exits(([
	"east" :MROOMS+"meldh1"
    ]));
}
void init() {
  ::init();
  add_action("move","move");
}
int move(string str) {
    if(!str) {
        tell_object(TP,"move what?");
        return 1;
    }
  if(str == "crate"){
     if(member_array("hole",TO->query_exits()) != -1) {
        	tell_object(TP,"Look Bub!  The crate has already been moved!  Duh!.");
            return 1;
            }
     tell_object(TP,"You wrestle the crate out of the way and see a hole in the wall "+
     		"leading into the darkness!\n");
     tell_room(ETP,""+TPQCN+" grunts and groans against the crate until it is moved out "+
     		"of the way.  You see a hole in the wall leading into the darkness",TP);
     add_exit(MROOMS+"mel8d","hole");
     return 1;
     }
}
