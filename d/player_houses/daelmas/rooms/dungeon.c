//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
	::create();
   set_name("Dungeon");
   set_short("dungeon");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
    	"You've reached the top of the tower. This room is "+
    	"rather plain and lacks the extravagance of the rest "+
    	"of the tower.  There is a simple mat thrown onto the "+
    	"floor and a small basin of water rests beside it.  "+
    	"Otherwise, the stone walls are dull and dusty, and "+
    	"the wooden door is scratched, as if someone or something "+
    	"had been clawing at it.  The only impressive part of this "+
    	"room is the view from the small, barred window.  From the "+
    	"window, one is able to look out over the ocean.  It is so "+
    	"hot and still up here that breathing is difficult.\n%^RESET%^"
  	);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","A strange odor of dust and heat assaults your senses.");
   set_listen("default","The silence of the room is stifling.");
   set_items(([
		"mat" : "The mat doesn't look very comfortable, and is old and stained.\n",
		"window" : "The window is small enough that nobody could possibly get "+
			"in or out, yet it is barred. A single ray of light shines "+
			"through. Looking out the window, one is reminded of how "+
			"incredibly tiny they are  in comparison to the rest of "+
			"the world.\n"
	]));

   set_door("trapdoor",DROOMS+"land6","down","marble key");
   set_locked("trapdoor",1,"lock");
   lock_difficulty("trapdoor", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");
   set_lock_description("trapdoor","lock","The lock is recessed and "+
   	"looks to be very intricate.");
   (DROOMS+"land6")->set_locked("trapdoor",1,"lock");
   set_door_description("trapdoor","The door is made of heavy oak and "+
   	"reinforced with iron bands.");
   set_string("trapdoor","open","You open the door onto the sixth landing.\n");

   set_exits(([
		"down" : DROOMS+"land6"
   ]));

   new(DOBJ+"gruel")->move(TO);
   new(DOBJ+"twater")->move(TO);
}
void init() {
  	::init();
  	add_action("sit","sit");
}
int sit(string str) {
 	if(!str) {
   	tell_object(TP,"Sit where?");
      return 1;
   }
  	if(str == "mat" || str == "on mat"){
   	tell_object(TP,"%^BOLD%^Your body aches as you try to get comfortable on "+
      	"the old mat.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sighs and shifts uncomfortably "+
        	"as "+TP->query_subjective()+" sits on the mat.\n%^RESET%^",TP);
		return 1;
 	}
}