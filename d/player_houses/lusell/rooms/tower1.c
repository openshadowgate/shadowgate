//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower1");
  	set_exits(([
   	"down" : LROOMS+"post0",
		"west" : LROOMS+"wall0",
  		"drawbridge" : LROOMS+"bridge"
  	]));

	set_invis_exits(({"drawbridge"}));
   set_pre_exit_functions(({"drawbridge"}),({"nogo"}));

  	set_door("door",LROOMS+"wall0","west","ruby key");
   set_door_description("door","The door is made "+
   	"of stout oak and bound in heavy bars of iron.  The door "+
   	"has deep scars as if it had repelled prospective invaders "+
   	"at least once before.\n");
   set_string("door","open","The door opens opens onto a walkway "+
   	"along the top of the wall.\n");
   set_locked("door",1,"lock");
	(LROOMS+"wall0")->set_locked("door",1,"lock");
  	lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
}
void init() {
  	::init();
  	add_action("check_em","check");
}
int check_em(string str) {
  	if(!str) {
   	tell_object(TP,"Check what?");
      return 1;
   }
  	if(str == "drawbridge"){
   	tell_object(TP,"%^BOLD%^You look down at the moat to see who "+
   		"is before the drawbridge.\n");
      TP->force_me("peer drawbridge 1");
    	return 1;
  	}
}
int nogo(){
  	if(avatarp(TP)) return 1;
  	if(interactive(TP))return 0;
}