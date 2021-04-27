//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
	::create();
   set_name("Balcony");
   set_short("balcony");
   set_long(
   	"%^RESET%^"+
   	"The balcony circles the entire tower, giving you an "+
   	"exceptional view of the land and sea in all directions. "+
   	"The balcony itself matches the white marble of the rest "+
   	"of the tower, and is lined with benches. A short wall "+
   	"surrounds the edges of the balcony and is overhung with "+
   	"%^GREEN%^ivy%^RESET%^, which grows throughout the "+
   	"%^BOLD%^marble trellis %^RESET%^design of the wall. Four "+
   	"statues set on the wall support the stone roof over your "+
   	"head, and are also covered with %^GREEN%^green ivy%^RESET%^. "+
   	"As you look out over the edges of the balcony, you are "+
   	"almost overwhelmed by the beauty of the sea and the surrounding "+
   	"forests.  From up here, one is able to see as far as the eye "+
   	"permits. The ocean reaches out to the horizon and is a "+
   	"beautiful, %^BLUE%^deep blue%^RESET%^. The land is brilliant "+
   	"shades of %^BOLD%^%^GREEN%^green %^RESET%^and "+
   	"%^ORANGE%^brown%^RESET%^. In the distance you can see a "+
   	"small village, the roads forming a criss-cross pattern "+
   	"throughout the impossibly small houses, and eventually "+
   	"trailing off into the dark surrounding forests.  \n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is filled with fresh scents of every kind.");
   set_listen("default","You hear the wind as it rushes by you.");
   set_items(([
   	({"statue","statues"}) : "The statues act as pillars, holding up "+
   		"the roof over the balcony. They appear to be of elven "+
   		"women, clad in white robes, with different thoughtful "+
   		"expressions upon their faces.\n",
   	"sea" : "Below you, waves of the sea crash against the side of "+
   		"the cliff.  The ocean looks very serene and beautiful "+
   		"from up here, and you see some ships sailing in the "+
   		"distance.\n",
   	({"forest","forests"}) : "The forests are vast and deep. There "+
   		"seems to be no end to them.\n",
   	"village" : "You don't think you've visited the village yet, "+
   		"and you wonder what kind of people live within the "+
   		"small houses.\n"
	]));

   set_door("glass door",DROOMS+"study","west","marble key");
   set_locked("glass door",1,"lock");
   (DROOMS+"study")->set_locked("glass door",1,"lock");
   set_door_description("glass door","The door is made of glass crystal.");
   set_string("glass door","open","You open the door into the study.\n");

	set_exits(([
		"west" : DROOMS+"study"
	]));

        set_climb_exits((["descend":({DROOMS+"garden",20,6,100})]));
  	set_fall_desc("%^BOLD%^%^RED%^You loose your grip and fall "+
  		"several feet only to land crashing and painfully into the "+
  		"garden!%^RESET%^\n");
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
  	if(str == "bench" || str == "on bench"){
     	tell_object(TP,"%^BOLD%^You sit down, relax and take a "+
     		"good look at the world around you.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sits down on the bench and reflects "+
        	"on the magnificent view.\n%^RESET%^",TP);
		return 1;
   }
}
