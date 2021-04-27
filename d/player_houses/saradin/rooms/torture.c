//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;

int TAKEN;

void create(){
	::create();
	set_name("torture chamber");
   set_short("torture chamber");
   set_long(
   	"%^BOLD%^%^RED%^"+
   	"This room is a gruesome site to behold.  All around "+
   	"you are torture devices and small little "+
   	"contraptions that could surely prove to be "+
   	"very painful.  A large cell is in the northwest "+
   	"corner and has a solid lock on its door.  You see "+
   	"various implements of torture: knives, pokers, swords, "+
   	"tongs, clamps, and whips all hanging, organized, "+
   	"in their places.  You also see a rack, bed, and "+
   	"brazier complete the room."+
   	"%^RESET%^"
   );
  	set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_smell("default","The smell of sweat and burnt flesh assails you.");
	set_listen("default","Chains lightly clinking against one another can be heard.");
	set_items(([
     	"bed" : "The bed looks comfortable and is large enough for two people.  "+
     		"You notice attached to each corner of the bed is a chain and the "+
     		"chains each end in a leather cuffs.\n",
     	"rack" : "This table has ropes at one end for securing the feet.  The "+
     		"rope at the other end attaches to the victim's wrists and to a "+
     		"wench.  The wench can then be turned with a crank and the rope is "+
     		"pulled taut stretching the victim in a most uncomfortable manner.  "+
     		"The table is large enough to handle victims from goblin size to "+
			"firbolg\n",
     	({"implements","knives","pokers","tongs","clamps","whips"}) : "Various "+
     		"items used in the pursuit of causing pain to another are "+
     		"hanging collectively in the southwest corner.  The collection "+
     		"seems to be very complete with every contingency of agony "+
     		"considered.\n",
     	"swords" : "The swords look very sharp and used.  Sitting with the "+
     		"swords you see a scimitar, curious as it is the only one and is "+
     		"buried amoungst the other swords.\n",
     	"brazier" : "Coals can be lit in the brazier to create a small fire.  It "+
     		"is more likely that fire is used to heat the pokers hanging nearby "+
			"rather than to heat the room.\n"
        	]));
   set_exits(([
		"east" : SROOMS+"hall1",
		"cell" : SROOMS+"cell",
  		"prisoners" : SROOMS+"cell"
  	]));

	TAKEN = 0;
	
	set_search("swords","The swords are mundane, but extremely well kept.  "+
		"With the swords you find one scimitar, but it is burried and you "+
		"will have to extract it to get it out and look at it closer.\n");
		
	set_invis_exits(({"prisoners"}));
   set_pre_exit_functions(({"prisoners"}),({"nogo"}));

  	set_door("iron door",SROOMS+"hall1","east","black skeleton key");
   set_door_description("iron door","This is a massive iron door.\n");
   set_string("iron door","open","The iron door was balanced perfectly "+
  		"because it opened with little effort into a hall.\n");

   set_door("cell door",SROOMS+"cell","cell","black skeleton key");
   set_door_description("cell door","The door is made of very thick iron bars.\n");
   set_string("cell door","open","The door creaks open to a dimly lit cell.\n");
   set_locked("cell door",1,"lock");
   lock_difficulty("cell door", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");
}

void init() {
  	::init();
  	add_action("check_em","check");
  	add_action("get_em","extract");
}

int get_em(string str) {
  	if(!str) {
   	tell_object(TP,"Extract what?");
      return 1;
   }
  	if(str == "scimitar"){
  		if(TAKEN == 1){
  			tell_object(TP,"%^BOLD%^What scimitar?\n");
  			return 1;
  		}
  		TAKEN = 1;
   	tell_object(TP,"%^BOLD%^You dig through the blades taking care "+
   		"not to cut yourself and finally free the scimitar.\n");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" rummages through the swords and "+
      	"uncovers a scimitar.\n",TP);
		new("/d/avatars/tristan/scimitar")->move(TO);
     	add_item("swords","The swords look very sharp and used.\n");
		set_search("swords","The swords are mundane, but extremely well kept.\n");		
		return 1;
  	}
}

int check_em(string str) {
  	if(!str) {
   	tell_object(TP,"Check what?");
      return 1;
   }
  	if(str == "prisoners"){
   	tell_object(TP,"You look through the bars to check on your prisoner.\n");
      tell_room((SROOMS+"cell"),""+TPQCN+" looks in on you through the bars.\n",TP);
      TP->force_me("peer prisoners 1");
    	return 1;
  	}
}

int nogo() {
  	if(avatarp(TP)) return 1;
  	if(interactive(TP))return 0;
}