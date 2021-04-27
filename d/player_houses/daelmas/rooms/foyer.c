//Coded by Diego//
//Changes made by Circe 2/16/04 per Saradin's request

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void moving(object tp, int num);

void create(){
  	::create();
   set_name("Foyer");
   set_short("foyer");
   set_long(
   	"%^RESET%^"+
    	"Tall %^BOLD%^white marble walls%^RESET%^ tower over your "+
    	"head as you enter the foyer, along with the %^BOLD%^white pillars "+
		"%^RESET%^which support the ceiling above you.  Small patterns "+
		"of %^GREEN%^leaves %^RESET%^have been painstakingly carved into "+
		"the ceiling and from it hangs a magnificent %^YELLOW%^gold "+
		"%^RESET%^and %^BOLD%^%^CYAN%^crystal chandelier%^RESET%^, which "+
		"provides lighting for the entire room.  Two %^BOLD%^%^BLACK%^black "+
		"marble gargoyles %^RESET%^sit upon %^YELLOW%^golden %^RESET%^pedestals "+
		"on either side of the arched entrance, contrasting greatly "+
		"with the mostly %^BOLD%^white room%^RESET%^.  The floor is "+
		"crafted with %^BOLD%^white %^RESET%^and %^BOLD%^%^BLACK%^gray "+
		"marble%^RESET%^, spiraling out from the center of the room.  On "+
		"the walls hang two large paintings and a display of highly "+
		"polished swords.  %^BOLD%^White steps%^RESET%^, beautifully "+
		"carved and covered with a %^RED%^thick red carpet%^RESET%^, begin "+
		"their ascension to the upper levels of the tower.  Torches line "+
		"the stairway, providing just enough light to maintain safety.  "+
		"Beneath the stairs is a %^ORANGE%^polished oak door%^RESET%^ and "+
		"a smaller set of steps which lead down into darkness.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
   	"chandelier" : "The beautiful chandelier hangs low above your "+
   		"head.  Eight white candles burn from behind their crystal "+
   		"covers. In the center, many crystals cluster together and "+
   		"hang down, catching the light and sending an array of colors "+
   		"around the room.  A faint jingle can be heard when a breeze "+
   		"catches the crystals.\n",
		({"gargoyle","gargoyles"}) : "These strike you as odd since gargoyles "+
			"are usually placed on the outside of houses.\n",
		"painting 1" : "This picture seems to portray a city.  The town is a "+
			"perfect circle, with walls dividing it into many sections. "+
			"The symmetry of the town is perfect, almost impossible, you "+
			"think.\n",
		"painting 2" : "Two figures stand in this picture, but it is dark "+
			"and you can not make out their faces.  They stand alone and "+
			"close, looking towards the moon and the stars in the "+
			"dark night.\n",
		({"paintings","painting"}) : "Maybe if you concentrated and looked "+
			"at painting 1 or painting 2 you might get more details.\n",
		({"sword","swords"}) : "Light reflects off the polished metal of "+
			"the blades.  They are long, clean and appear unused.",
		"stairway" : "The stairway is larger at the base and then grows "+
			"narrower as it ascends upwards. The steps are covered with "+
			"a thick red carpet.  The stairs are narrow leading downward.\n"
	]));

   set_door("oak door",DROOMS+"sitting","east","marble key");
   set_locked("oak door",1,"lock");
   (DROOMS+"sitting")->set_locked("oak door",1,"lock");
   set_door_description("oak door","The door is made of polished oak.");
   set_string("oak door","open","You open the door into the sitting room.\n");

   set_door("copper door",DROOMS+"torture","down","marble key");
   set_locked("copper door",1,"lock");
   (DROOMS+"torture")->set_locked("copper door",1,"lock");
   set_door_description("copper door","The door is made of from a "+
   	"common wood and covered in copper sheeting.");
   set_string("copper door","open","You open the door to steps "+
   	"leading down into a torture chamber.\n");

   set_door("large door",DROOMS+"garden","south","marble key");
   set_door_description("large door","The door is large polished and made from oak.");
   set_string("large door","open","You open the door into the garden.\n");

   set_exits(([
		"east" : DROOMS+"sitting",
		"up" : DROOMS+"land2",
		"down" : DROOMS+"torture",
		"south" : DROOMS+"garden"
	]));

	set_trap_functions(({"up"}),({"move_em"}),({"up"}));

}
void init() {
  	::init();
  	add_action("disarm_em","touch");
}
int disarm_em(string str) {
   if(!str) {
     	tell_object(TP,"%^BOLD%^%^CYAN%^Touch yourself? Nasty!");
     	return 1;
   }
  	if(str == "gargoyle"){
     	tell_object(TP,"%^BOLD%^You reach out and touch a "+
     		"gargoyle statue to toggle the trap on the stairs.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reaches out and "+
        	"curiously touches a gargoyle statue.\n%^RESET%^",TP);
//		toggle_trap("up");
		return 1;
   }
  	if(str == "gargoyle twice"){
     	tell_object(TP,"%^BOLD%^You reach out and touch a "+
     		"gargoyle statue to toggle the trap on the stairs.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reaches out and "+
        	"curiously touches a gargoyle statue.\n%^RESET%^",TP);
		toggle_trap("up");
		return 1;
   }
}
int move_em(){
  if(!TP->query_true_invis()){
   if(interactive(TP)){
		tell_object(TP,"%^BOLD%^%^MAGENTA%^You start up the stairs and hear "+
			"a clicking noise as you place weight on the steps.\n");
		tell_room(ETP,"%^BOLD%^%^MAGENTA%^You heard a clicking noise "+
			"as "+TPQCN+" starts up the stairs.\n",TP);
   	TP->force_me("emote looks suddenly concerned.");
   	moving(TP,0);
		return 1;
	}
   }
}
void moving(object tp,int num){
 	switch(num){
   	case(0):
   		tell_object(TP,"%^MAGENTA%^A fog issues forth out of the "+
      		"gargoyle's mouths and envelopes you.\n");
         tell_room(ETP,"%^MAGENTA%^"+TPQCN+" is suddenly enveloped in a "+
         	"mystical fog that issues out of the gargoyle's mouths.\n",TP);
      	TP->set_paralyzed(5000,"%^MAGENTA%^You are immobilized by the "+
      		"billowing magic fog!");
         break;
    	case(1):
    		tell_object(TP,"%^MAGENTA%^You can no longer see the room as "+
         	"the fog closes in on you.\n");
       	TP->move(DROOMS+ "dungeon");
         tell_room((DROOMS+("foyer")),"%^MAGENTA%^"+TPQCN+" is completely "+
         	"enclosed by the fog.\n",TP);
         break;
    	case(2):
    		tell_object(TP,"%^MAGENTA%^The fog seeps beneath your clothing "+
         	"and invades your every pore, you feel your body tingle "+
          	"all over.\n");
			tell_room((DROOMS+("foyer")),"%^MAGENTA%^The fog pulses "+
				"with %^YELLOW%^light %^RESET%^%^MAGENTA%^and a "+
				"%^BOLD%^%^BLUE%^m%^RED%^u%^GREEN%^l"+
				"%^YELLOW%^t%^WHITE%^i%^BLACK%^t%^MAGENTA%^u%^CYAN%^d%^GREEN%^e"+
				"%^RESET%^%^MAGENTA%^ of colors! \n",TP);
        	break;
     	case(3):
     		tell_object(TP,"You feel yourself begin to fade.\n");
         tell_room((DROOMS+("foyer")),"%^MAGENTA%^The magic fog begins to "+
           		"expand and contract rapidly! \n",TP);
         break;
    	case(4):
    		tell_object(TP,"%^MAGENTA%^Your senses are numbed by and you feel "+
         	"as though your moving, but you do not know how you "+
          	"can tell this!\n");
        	tell_room((DROOMS+("foyer")),"%^MAGENTA%^The fog shimmers and starts to "+
         	"dissipate.  "+TPQCN+" is no where to be seen!!!\n",TP);
         break;
     	case(5):
     		tell_object(TP,"%^MAGENTA%^You find yourself materializing "+
         	"on the floor in a small dingy room.\n");
         tell_room(ETP,"%^MAGENTA%^"+TPQCN+" materializes out of thin air.\n",TP);
         TP->set_paralyzed(0);
			return;
 	}
   num++;
   call_out("moving",0,tp,num);
   return;
}
void reset(){
   ::reset();
   if(!trapped("up"))toggle_trap("up");
}
