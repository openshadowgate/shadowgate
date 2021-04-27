//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

int SCIM,HAM,MAXE,THS,WHP,BKN,KNF,HAL,STF,SP,PIT;

void create(){
 	::create();
   set_name("Dueling room");
   set_short("dueling room");
   set_long(
   	"%^RESET%^"+
   	"This room is obviously the showpiece for the owner of "+
   	"the tower.  Rows of weapons line all the walls.  The walls "+
   	"themselves are the same as the rest of the tower and are "+
   	"polished smooth.  Along the bottom of the walls a script is "+
   	"written over and over.  In the center of the room is a large "+
   	"open pit with soft dirt covering the bottom.  A long chain "+
   	"hangs from the ceiling and dangles near the edge of the pit.  "+
   	"Racks of weapons as mounted on the floor near the pit.\n"
  	);
  	set_terrain(STONE_BUILDING);
  	set_travel(PAVED_ROAD);
  	set_property("indoors",1);
   set_property("light",2);
   set_smell("default","Though clean, the smell of sweat and blood can "+
   	"barely be discerned.");
   set_listen("default","You can hear the sound of the waves crashing "+
   	"against the rock below.");
   set_items(([
		"weapons" : "The collection of weapons is extraordinary.  Weapons "+
			"of all types lines these walls and obviously must have taken "+
			"some time to collect.\n",
		"floor" : "The stones are flat and sparkle faintly. You "+
			"recognize the pattern displayed here.\n",
		"window" : "The window opens to a breathtaking view of the "+
			"sea with the waves crashing powerfully into the cliffs below.\n",
		"pit" : "The floor of the large pit is sand and is smoothed down "+
			"so it would be comfortable to the feet.  Looking closely you "+
			"see that there is still blood streaks in the sand, most likely "+
			"from past battles.\n",
		"chain" : "This long black chain hangs awkwardly near the edge of the pit.\n",
		({"racks","weapon racks"}) : "On the racks you see numerous scimitars, "+
			"warhammers, battleaxes, two handed swords, whips, brass knuckles, "+
			"knives, halberds, staves, and spears.\n"
	]));

	set("read script","%^BOLD%^%^CYAN%^Through strength we grow, through "+
		"cunning we live.%^RESET%^\n");
   set("language","common");

   set_door("eastern door",DROOMS+"land3","west","marble key");
   set_door_description("eastern door","The door is polished and made from oak.");
   set_string("eastern door","open","You open the door onto the landing.\n");

   set_exits(([
		"west" : DROOMS+"land3"
   ]));
}
void init() {
  	::init();
  	add_action("pull_em","pull");
  	add_action("choose_em","choose");
}
int pull_em(string str) {
  	if(!str) {
    	tell_object(TP,"Pull what?");
     	return 1;
  	}
  	if(str == "chain"){
  		if(PIT == 0){
     		tell_object(TP,"%^BOLD%^%^BLACK%^You pull the chain and the "+
     			"room shakes as the pit deepens and the racks of weapons "+
     			"tilt towards the pit handles first offering you your "+
     			"choice of weapons.\n%^RESET%^");
      	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" pulls the chain and "+
      		"the room suddenly shakes as the pit deepens and the racks "+
      		"of weapons tilt toward the pit, handles first offering you "+
      		"your choice of weapons.\n%^RESET%^",TP);
      	PIT = 1;
      }else{
     		tell_object(TP,"%^BOLD%^%^BLACK%^You pull the chain and the "+
     			"room shakes as the pit raises back to its former level "+
     			"and the racks of weapons tilt backward until they sit "+
     			"upright again.\n%^RESET%^");
      	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" pulls the chain and "+
      		"the room suddenly shakes as the pit raises back to its "+
      		"former level and the racks of weapons tilt backward until "+
      		"they sit upright again.\n%^RESET%^",TP);
      	PIT = 0;
      }
		return 1;
 	}
}
int choose_em(string str) {
  	if(!str) {
    	tell_object(TP,"%^BOLD%^Choose which weapon?");
     	return 1;
  	}
  	if(str){
    	switch(str) {
    		case "scimitar":
    			if(SCIM < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the scimitar.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the scimitar.\n");
					new(CWEAP+"scimitar")->move(TP);
					SCIM = SCIM + 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "medium hammer":
    			if(HAM < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the warhammer.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the warhammer.\n");
					new(CWEAP+"warhammer")->move(TP);
					HAM = HAM = 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
     		case "warhammer":
    			if(HAM < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the warhammer.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the warhammer.\n");
					new(CWEAP+"warhammer")->move(TP);
					HAM = HAM = 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
   		case "medium axe":
    			if(MAXE < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the battleaxe.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the battleaxe.\n");
					new(CWEAP+"battle_axe")->move(TP);
					MAXE = MAXE +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
   		case "battleaxe":
    			if(MAXE < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the battleaxe.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the battleaxe.\n");
					new(CWEAP+"battle_axe")->move(TP);
					MAXE = MAXE +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
   		case "battle axe":
    			if(MAXE < 3){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the battleaxe.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the battleaxe.\n");
					new(CWEAP+"battle_axe")->move(TP);
					MAXE = MAXE +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "two handed sword":
    			if(THS < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the two handed sword.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the two handed sword.\n");
					new(CWEAP+"two_hand_sword")->move(TP);
					THS = THS + 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "two-handed sword":
    			if(THS < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the two handed sword.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the two handed sword.\n");
					new(CWEAP+"two_hand_sword")->move(TP);
					THS = THS + 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "whip":
    			if(WHP < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the whip.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the whip.\n");
					new(CWEAP+"whip")->move(TP);
					WHP = WHP +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "brass knuckles":
    			if(BKN < 4){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the brass knuckles.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the brass knuckles.\n");
					new("/d/antioch/antioch2/obj/knuckles")->move(TP);
					BKN = BKN +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "knife":
    			if(KNF < 4){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the knife.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the knife.\n");
					new(CWEAP+"knife")->move(TP);
					KNF = KNF +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "halberd":
    			if(HAL < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the halberd.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the halberd.\n");
					new(CWEAP+"halberd")->move(TP);
					HAL = HAL + 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "staff":
    			if(STF < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the quarterstaff.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the quarterstaff.\n");
					new(CWEAP+"quarter_staff")->move(TP);
					STF = STF +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "quarterstaff":
    			if(STF < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the quarterstaff.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the quarterstaff.\n");
					new(CWEAP+"quarter_staff")->move(TP);
					STF = STF +1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
    		case "spear":
    			if(SP < 2){
    				tell_room(ETP,"%^BOLD%^"+TPQCN+" chooses the spear.\n",TP);
    				tell_object(TP,"%^BOLD%^You choose the spear.\n");
					new(CWEAP+"mspear")->move(TP);
					SP = SP + 1;
				}else tell_object(TP,"%^BOLD%^Choose another weapon, there "+
					"are none of this type left.\n");
    			return 1;
			default:
    			tell_object(TP,"%^BOLD%^Try choosing a weapon that is in the racks.\n");
    			return 1;

    	}
 	}
}
