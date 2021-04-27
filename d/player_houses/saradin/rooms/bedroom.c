//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;

int DRAWER, BALL;

void create(){
	::create();
	set_name("bedroom");
   set_short("bedroom");
   set_long(
   	"%^RESET%^%^GREEN%^"+
   	"This room has a large king size bed with a large backboard.  "+
   	"Two lamps light the room from the corners and a dresser "+
   	"sits in the northeast corner.  An armoire sits on the west "+
   	"side of the room.  On the armoire lies a piece of scrimshaw.  "+
   	"The floor is covered with a soft rug."+
		"%^RESET%^"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_smell("default","The room smells of clean linen.");
	set_listen("default","You hear only the sounds you bring to this room.");
	set_items(([
		"bed" : "The bed is a large one.  It looks to be firm yet "+
			"comfortable and is covered in fresh linens and satin.\n",
		"armoire" : "Made of fine black walnut this armoire looks "+
			"to be of the finest quality.\n",
		"dresser" : "The dresser if made of flawless mahogany and "+
			"looks to be very expensive.\n",
		"backboard" : "The backboard to the bed it carve from a "+
			"single piece of a mysterious, but beautiful wood.  A "+
			"scene of two ships engaged in a sea battle is carved "+
			"with great skill into the wood and the scene seems to "+
			"move magically as you watch it.\n"
   ]));

   set_exits(([
		"northwest" : SROOMS+"living_area"
  	]));
  	
   set_search("dresser","You find the dresser has one drawer, but "+
	"it seems to be stuck.  You will have to force it to see what is inside.\n");
	
   set_door("bedroom door",SROOMS+"living_area","northwest");
   set_door_description("bedroom door","This is a simple wooden door with a lock.\n");
   set_string("bedroom door","open","The door opens quietly into the living area.\n");
   DRAWER = 0;
   BALL = 0;
}

void init() {
  	::init();
  	add_action("force_em","force");
  	add_action("close_em","close");
}

int force_em(string str) {
   if(!str) {
      tell_object(TP,"Force what?");
      return 1;
   }
   if(str == "drawer" || str == "the drawer"){
  	if(DRAWER == 1) {
  		tell_object(TP,"%^BOLD%^The drawer is already open.\n");
  		return 1;
  	}
  	if(BALL == 1){
  		tell_object(TP,"%^BOLD%^The drawer is empty.\n");
  		return 1;
  	}  			
  	DRAWER = 1;
  	BALL = 1;
        tell_object(TP,"You open the drawer and find a glass sphere inside.\n");
     	tell_room(ETP,""+TPQCN+" opens the dresser drawer.\n",TP);
  	if(!present("ball")) 
            new("/d/tharis/barrow/obj/sphere.c")->move(TO);
     	return 1;
    }
    return 1;
}
int close_em(string str) {
   if(!str) {
      tell_object(TP,"Close what?");
      return 1;
   }
   if(str == "drawer" || str == "the drawer"){
  	if(DRAWER == 0) {
  		tell_object(TP,"%^BOLD%^The drawer is already closed.\n");
  		return 1;
  	}
     	tell_object(TP,"You close the drawer.\n");
  	tell_room(ETP,""+TPQCN+" closes the drawer.\n",TP);
     	DRAWER = 0;
     	return 1;
   }
// changed to return 0 so close bedroom door will work when Saradin had a problem with it  *Styx*  2/9/03
        return 0;
}

void reset(){
   ::reset();
  	if(!present("rod")) {
		new(SOBJ+"scrim_rod")->move(TO);
  	}
}
