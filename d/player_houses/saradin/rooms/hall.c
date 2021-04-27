//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit WATER;

int ROD_IN, FLAG, FLAG2,TRAPPING;

void drowning(object tp, int num);
void draining(object tp, int num);

void create(){
	::create();
	set_name("hall");
   set_short("hall");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This is a secret hallway leading to the west and northeast.  "+
   	"The walls have grooves in them and this is similar "+
   	"to the first hallway in craftmanship.  Along both "+
   	"sides of the hall there are holes about 3 feet off "+
   	"the ground at regular intervals."+
   	"%^RESET%^"
   );
  	set_surface(1);
  	set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",1);
	set_smell("default","The air is oppressive in this small hallway.");
	set_listen("default","You can hear the faint clinking of chains to the west.");
	set_items(([
		"floor" : "The floor is clean and made of finely cut stone that has "+
			"been expertly fitted together.\n",
		"ceiling" : "The ceiling is about ten feet above and lost in the shadows.\n",
		({"wall","walls"}) : "The walls have regularly spaced holes "+
			"about inch in diameter approximately 3 feet off the floor.\n",
		({"holes","hole"}) : "The holes are about one inch in diameter.\n"
   ]));

	set_search("holes","The holes look to be about one inch in "+
		"diameter and are at regular intervals.  The holes look to be damp inside.  "+
		"The center hole on the south wall has a rectangular indentation around "+
		"it and the inner surface of the hole is scuffed.\n");
	set_search("hole","The holes look to be about one inch in "+
		"diameter and are at regular intervals.  The center hole "+
		"on the south wall has a rectangular indentation around "+
		"it and the inner surface of the hole is scuffed.\n");
	set_search("center hole","The center hole on the south wall "+
		"is scuffed n the inner surfaces like something has been "+
		"inserted into it.  The rectangular indentation around the "+
		"hole seems to be of separate construction from the rest "+
		"of the wall and scratches in the retangular surface look "+
		"like the rectangle has been moved up or down.\n");

	set_trap_functions(({"northeast","west"}),(
							{"drown_em2","drown_em"}),
							({"northeast","west"}));

	ROD_IN = 0;
	FLAG = 0;
	FLAG2 = 0;
	TRAPPING = 0;

   set_exits(([
		"west" : SROOMS+"hall1",
		"northeast" : SROOMS+"hall0"
  	]));
}
void init() {
  	::init();
  	add_action("insert_em","insert");
  	add_action("lift_em","lift");
  	add_action("disarm_em","press");
}
int disarm_em(string str) {
   if(!str) {
     	tell_object(TP,"%^BOLD%^%^CYAN%^Press what?!");
     	return 1;
   }
	if(FLAG2 == 1){
		tell_object(TP,"%^BOLD%^Don't you think it is a little too late for that?\n");
		return 1;
	}
  	if(str == "third stone on the south wall" ||
  		str == "third stone on south wall" ||
  		str == "3rd stone on the south wall" ||
  		str == "3rd stone on south wall"){
     	tell_object(TP,"%^BOLD%^You reach out and press the third stone "+
     		"on the south wall.  You hear a satisfying click.\n%^RESET%^");
     	tell_room(TO,"%^BOLD%^"+TPQCN+" reaches out and "+
        	"presses a stone on the south wall.  You hear a click.\n%^RESET%^",TP);
      if(trapped("west"))toggle_trap("west");
      if(trapped("northeast"))toggle_trap("northeast");
		return 1;
	}
}
int lift_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Lift what where?");
      return 1;
   }
	if(ROD_IN == 0){
		tell_object(TP,"%^BOLD%^You need to insert the rod first!");
		return 1;
	}
	if(str == "rod") {
   	tell_object(TP,"%^BOLD%^Lift rod upward or downward?");
      return 1;
   }
	if(str == "rod downward" || str == "rod down") {
		tell_room(TO,"%^BOLD%^"+TPQCN+" pushes the rod downward.\n");
   	tell_object(TP,"%^BOLD%^The rod crumbles and nothing "+
   		"happens, you chose poorly!\n");
      return 1;
   }
	if(str == "rod upward" || str == "rod up"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" lifts up on the rod.\n");
		call_out("draining",0,TP,0);
		tell_room(TO,"The rod crumbles.\n");
		ROD_IN = 0;
		return 1;
	}
}
int insert_em(string str) {
	object obj;
	if(!str) {
   	tell_object(TP,"Insert what into where?");
      return 1;
   }
	if(str == "rod into hole" || str == "rod into the hole" || str == "rod into center hole"
		|| str == "rod into the center hole" || str == "rod in hole"
		|| str == "rod in the hole" || str == "rod in center hole"
		|| str == "rod in the center hole"){
		if(FLAG == 1){
			tell_object(TP,"%^BOLD%^You can't do that, something is "+
				"already jamming the hole!\n");
			return 1;
		}
		if(TRAPPING == 1){
			tell_object(TP,"%^BOLD%^You can't do that while water is "+
				"gushing from the hole, try again when the water stops pouring out!\n");
			return 1;
		}
		if(obj = present("rod",TP)){
			ROD_IN = 1;
			tell_room(TO,"%^BOLD%^"+TPQCN+" inserts the rod into the center hole.\n");
			obj->remove();
			FLAG = 1;
			return 1;
		}else{
			tell_object(TP,"%^BOLD%^You don't have a rod!\n");
			return 1;
		}
	}
}
int drown_em(string str) {
   if(interactive(TP)){
		if(FLAG2 == 1) return 1;
		FLAG2 = 1;
		tell_object(TP,"%^BOLD%^You move west and feel a block in the floor "+
			"give under your weight ever so slightly.\n");
		tell_room(TO,"%^BOLD%^"+TPQCN+" starts west then freezes.\n",TP);
		TP->force_me("emote %^BOLD%^gulps worriedly");
		remove_exit("northeast");
		remove_exit("west");
		(SROOMS+"hall0")->remove_exit("southwest");
		(SROOMS+"hall1")->remove_exit("east");
   	call_out("drowning",0,TP,0);
   	return 1;
   }
}
int drown_em2(string str) {
   if(interactive(TP)){
		if(FLAG2 == 1) return 1;
		FLAG2 = 1;
		tell_object(TP,"%^BOLD%^You move northeast and feel a block in the floor "+
			"give under your weight ever so slightly.\n");
		tell_room(TO,"%^BOLD%^"+TPQCN+" starts northeast then freezes.\n",TP);
		TP->force_me("emote %^BOLD%^gulps worriedly");
		remove_exit("northeast");
		remove_exit("west");
		(SROOMS+"hall0")->remove_exit("southwest");
		(SROOMS+"hall1")->remove_exit("east");
   	call_out("drowning",0,TP,0);
   	return 1;
   }
}
void drowning(object tp,int num){
     	switch(num){
      	case(0):
      		TRAPPING = 1;
	      	tell_room(TO,"%^BOLD%^%^CYAN%^Stone walls slam down "+
	      		"blocking the exits to the northeast and the west.\n");
   			(SROOMS+"hall0")->set_long("%^BOLD%^%^BLACK%^"+
   				"This is a secret hallway leads to a blank wall in the southwest.  "+
   				"The wall in the southwest has a hole in the center.  The hole is about an "+
   				"inch in diameter with a rectangular box around it.  The walls "+
   				"have grooves in them and this is similar "+
   				"to the first hallway in craftmanship."+
   				"%^RESET%^");
   			(SROOMS+"hall1")->set_long("%^BOLD%^%^BLACK%^"+
   				"This is a secret hallway leads to a blank wall in the east.  "+
   				"The wall in the east has a hole in the center The hole is about an "+
   				"inch in diameter with a rectangular box around it.  The walls "+
   				"have grooves in them and this is similar "+
   				"to the first hallway in craftmanship."+
   				"%^RESET%^");
   			(SROOMS+"hall0")->set_search("hole","The hole in the southwest wall "+
					"is scuffed on the inner surfaces like something has been "+
					"inserted into it.  The rectangular indentation around the "+
					"hole seems to be of separate construction from the rest "+
					"of the wall and scratches in the retangular surface look "+
					"like the rectangle has been moved up or down.\n");
   			(SROOMS+"hall1")->set_search("hole","The hole in the east wall "+
					"is scuffed on the inner surfaces like something has been "+
					"inserted into it.  The rectangular indentation around the "+
					"hole seems to be of separate construction from the rest "+
					"of the wall and scratches in the retangular surface look "+
					"like the rectangle has been moved up or down.\n");
            break;
        	case(1):
            break;
       	case(2):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^You hear a squeaking sound "+
	      		"beind the walls then water starts to trickle from the holes in the wall.\n");
				break;
        	case(3):
            break;
        	case(4):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water starts to pour from "+
	      		"the holes more forcefully and the water covers your feet.\n");
            break;
        	case(5):
            break;
        	case(6):
				tell_room(TO,"%^BOLD%^%^CYAN%^Water continues to pour into "+
					"the room and with no outlet the water depth is about one foot deep.\n");
            break;
        	case(7):
            break;
        	case(8):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water level continues to "+
	      		"rise and is now at least two feet deep.\n");
            break;
        	case(9):
            break;
        	case(10):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^This will be serious soon, "+
	      		"the water level is still rising and is now at least three feet deep.\n");
            break;
        	case(11):
            break;
        	case(12):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^Boy that water is cold, four "+
	      		"feet deep and rising!\n");
            break;
        	case(13):
            break;
        	case(14):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^Better grow some gills soon, "+
	      		"the water is now five feet deep and still rising!\n");
            break;
        	case(15):
            break;
        	case(16):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^How long can you tred water?  "+
	      		"The water is six feet deep and soon will reach the ceiling!\n");
            break;
        	case(17):
            break;
        	case(18):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water is seven feet deep "+
	      		"and rising, soon there will be no head room and you will "+
	      		"have to hold your breath.\n");
            break;
        	case(19):
            break;
        	case(20):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water is eight feet deep "+
	      		"and still rising!  The ceiling is about two feet away, "+
	      		"you do the math!!\n");
            break;
        	case(21):
            break;
        	case(22):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^Nine feet deep and unless "+
	      		"your are very tall you have begun treading water!  "+
	      		"The water will soon reach the ceiling!!\n");
            break;
        	case(23):
            break;
        	case(24):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water has now reached "+
	      		"the ceiling and no air pockets can be found!  Where "+
	      		"are those gills when you need them?!?!\n");
	      	TRAPPING = 0;
            break;
        	case(25):
				set_surface(0);
				set_property("underwater",1);
				set_smell("default","Water fills your nostrils as you get ready to inhale.");
				set_listen("default","You hear the water in your ears.");
				toggle_trap("west");
				toggle_trap("northeast");
            return;
         case(26):
         	set_surface(1);
         	remove_property("underwater");
				set_smell("default","The air is damp  and oppressive in this small hallway.");
				set_listen("default","You can hear the faint dripping of water and "+
					"the clinking of chains to the west.");
   			(SROOMS+"hall0")->set_long("%^BOLD%^%^BLACK%^"+
   				"This is a secret hallway leads to the southwest.  "+
   				"The walls have grooves in them and this is similar "+
   				"to the first hallway in craftmanship."+
   				"%^RESET%^");
   			(SROOMS+"hall1")->set_long("%^BOLD%^%^BLACK%^"+
   				"This is a secret hallway leads to the east and an iron door in the west.  "+
   				"The walls have grooves in them and this is similar "+
   				"to the first hallway in craftmanship."+
   				"%^RESET%^");
   			add_exit(SROOMS+"hall0","northeast");
   			add_exit(SROOMS+"hall1","west");
   			(SROOMS+"hall0")->add_exit(SROOMS+"hall","southwest");
   			(SROOMS+"hall1")->add_exit(SROOMS+"hall","east");
   			return;
        	case(27):
            return;
        	case(28):
            return;
    	}
    	num++;
    	call_out("drowning",0,tp,num);
    	return;
}
void draining(object tp,int num){
     	switch(num){
      	case(0):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^You hear a distant click and then "+
	      		"a grinding sound.\n");
            break;
        	case(1):
            break;
         case(2):
            break;
        	case(3):
            break;
        	case(4):
        		tell_room(TO,"%^BOLD%^%^CYAN%^You hear the sounds of metal "+
        			"screeching as it protests against movement then silence.\n");
        		tell_room((SROOMS+"hall0"),"%^BOLD%^%^CYAN%^You hear the sounds of metal "+
        			"screeching as it protests against movement then silence.\n");
        		tell_room((SROOMS+"hall1"),"%^BOLD%^%^CYAN%^You hear the sounds of metal "+
        			"screeching as it protests against movement then silence.\n");
            break;
        	case(5):
            break;
        	case(6):
            break;
        	case(7):
            break;
        	case(8):
            break;
        	case(9):
        		tell_room(TO,"%^BOLD%^%^CYAN%^Stone grinds against stone from "+
        			"the bottom of the north and south wall.\n");
        		tell_room((SROOMS+"hall0"),"%^BOLD%^%^CYAN%^The grinding of stone "+
        			"can be heard through the southwest wall.\n");
        		tell_room((SROOMS+"hall1"),"%^BOLD%^%^CYAN%^The grinding of stone "+
        			"can be head through the east wall.\n");
            break;
      	case(10):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The water level starts to rapidly drop.\n");
				break;
        	case(11):
            break;
        	case(12):
	      	tell_room(TO,"%^BOLD%^%^CYAN%^The last of the water drains "+
	      		"out through slots at the base of the walls.\n");
            break;
        	case(13):
            break;
        	case(14):
				tell_room(TO,"%^BOLD%^%^CYAN%^The wall blocking the passage "+
					"to the northeast slides slowly back up into the ceiling.\n");
				tell_room((SROOMS+"hall0"),"%^BOLD%^%^CYAN%^The wall blocking the passage "+
					"to the southwest slides slowly back up into the ceiling.\n");
				tell_room((SROOMS+"hall1"),"%^BOLD%^%^CYAN%^The wall blocking the passage "+
					"to the east slides slowly back up into the ceiling.\n");
				call_out("drowning",0,tp,26);
				tell_room(TO,"%^BOLD%^%^CYAN%^Another harrowing escape?!?!\n");
            break;
    	}
    	num++;
    	call_out("draining",0,tp,num);
    	return;
}
void reset(){
   ::reset();
   if(!trapped("west"))toggle_trap("west");
   if(!trapped("northeast"))toggle_trap("northeast");
	ROD_IN = 0;
	FLAG = 0;
	FLAG2 = 0;
	TRAPPING = 0;
}
