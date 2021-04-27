//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

int OPEN;

void create(){
   ::create();
   set_name("bridge");
	set_short("drawbridge");
	set_long(
    	"%^RESET%^%^CYAN%^"+
		"To the north you see an imposing keep.  Guards are seen "+
		"walking the parapet and most likely archers are manning "+
		"the murder holes.  A moat filled with %^GREEN%^brackish green water "+
		"%^CYAN%^surrounds the keep and the only way in you can "+
		"see is the %^ORANGE%^drawbridge%^CYAN%^, which is currently closed.\n"+
		"%^RESET%^"
   );
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","Stagnant smells from the moat reach your nose.");
	set_listen("default","Frogs croak nearby in the moat.");
	set_items(([
   ]));
  	set_exits(([
		"south" : LROOMS+"to_tonovi"
	]));
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
	OPEN = 0;
}
void init() {
  ::init();
  add_action("yell_em","yell");
}
int GoThroughDoor(){
   if(!userp(TP)) return 0;
   return 1;
}
int yell_em(string str) {
 	if(!str) {
   	tell_object(TP,"Yell what?");
      return 1;
   }
  	if(str == "lower drawbridge" && OPEN == 0){
		if(member_array("bridge",TO->query_exits()) != -1) {
   		tell_object(TP,"%^BOLD%^Why are you yelling, the drawbridge is "+
   			"already lowered!");
			return 1;
		}
		tell_object(TP,"%^BOLD%^You yell for the guards to lower the drawbridge!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to lower the drawbridge!\n",TP);
		tell_room(ETP,"%^BOLD%^%^MAGENTA%^A voice calls from the "+
  			"keep: %^RESET%^WHO GOES THERE?\n");
     	OPEN = 1;
     	return 1;
	}else if(str == "emissary of fire" && OPEN == 1){
		tell_object(TP,"%^BOLD%^You yell 'EMISSARY OF FIRE'!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells 'EMISSARY OF FIRE'!\n",TP);
		tell_room(ETP,"%^BOLD%^You hear a clanking as the chains from the "+
			"drawbridge are slowly released and the bridge is lowered.\n");
		tell_room((LROOMS+"yard0"),"%^BOLD%^You hear a clanking as the chains from the "+
			"drawbridge are slowly released and the bridge is lowered.\n");
     	(LROOMS+"yard0")->add_exit(LROOMS+"bridge","bridge");
     	add_exit(LROOMS+"yard0","bridge");
		set_long(
    		"%^RESET%^%^CYAN%^"+
			"To the north you see an imposing keep.  Guards are seen "+
			"walking the parapet and most likely archers are manning "+
			"the murder holes.  A moat filled with %^GREEN%^brackish green water "+
			"%^CYAN%^surrounds the keep and the only way in you can "+
			"see is the %^ORANGE%^drawbridge%^CYAN%^, which is currently open.\n"+
			"%^RESET%^"
   	);
     	return 1;
   }else if(str == "raise drawbridge"){
   	if(member_array("bridge",TO->query_exits()) != -1) {
			tell_object(TP,"%^BOLD%^You yell for the guards to raise the "+
				"drawbridge!\n");
			tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to raise "+
				"the drawbridge!\n",TP);
			tell_room(ETP,"%^BOLD%^You hear a clanking as the chains from the "+
				"drawbridge are slowly pulled up and the bridge is raised.\n");
			tell_room((LROOMS+"yard0"),"%^BOLD%^You hear a clanking as the chains from the "+
				"drawbridge are slowly pulled up and the bridge is raised.\n");
   		remove_exit("bridge");
   		(LROOMS+"yard0")->remove_exit("bridge");
   		OPEN = 0;
			set_long(
    			"%^RESET%^%^CYAN%^"+
				"To the north you see an imposing keep.  Guards are seen "+
				"walking the parapet and most likely archers are manning "+
				"the murder holes.  A moat filled with %^GREEN%^brackish green water "+
				"%^CYAN%^surrounds the keep and the only way in you can "+
				"see is the %^ORANGE%^drawbridge%^CYAN%^, which is currently closed.\n"+
				"%^RESET%^"
   		);
   		return 1;
 		}else{
 			tell_object(TP,"%^BOLD%^The bridge is alrady raised!\n");
 			OPEN = 0;
 			return 1;
 		}
 	}
	TP->force_me("emote yells: %^BOLD%^"+str+"!");
 	return 1;
}