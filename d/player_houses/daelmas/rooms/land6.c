//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
	::create();
   set_name("Sixth landing");
   set_short("sixth landing");
   set_long(
   	"%^RESET%^"+
    	"The stairway comes to an end here. A small wooden door "+
    	"stands before.  Above you is a trapdoor with a barred window "+
    	"built into it. The barred window has a hinged door that is "+
    	"currently closed.\n"
  	);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
	]));

   set_door("trapdoor",DROOMS+"dungeon","up","marble key");
   set_door_description("trapdoor","The door is made of polished oak.");
   set_string("trapdoor","open","You open the trapdoor to the open dark "+
   	"and dingy room.\n");
   set_locked("trapdoor",1,"lock");
   lock_difficulty("trapdoor", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");

  	set_exits(([
		"down" : DROOMS+"land5",
		"up" : DROOMS+"dungeon",
   	"prisoners" : DROOMS+"dungeon"
	]));

   set_invis_exits(({"prisoners"}));
   set_pre_exit_functions(({"prisoners"}),({"nogo"}));

   if(!present("rubin")){
   	new(DMONS+"rubin")->move(TO);
   }

}

void init() {
  	::init();
  	add_action("check_em","check");
}

int nogo(){
  	if(avatarp(TP)) return 1;
  	if(interactive(TP))return 0;
}

int check_em(string str) {
  	if(!str) {
  		tell_object(TP,"Check what?");
      return 1;
   }
  	if(str == "prisoners"){
   	tell_object(TP,"You open the barred window in the trapdoor and peer "+
      	"into the room to check on the guests.\n");
     	tell_room(ETP,""+TPQCN+" opens the barred window in the trapdoor and "+
      	"peers inside.\n",TP);
      tell_room((DROOMS+"dungeon"),"You hear a noise as the little "+
      	"barred window in the trapdoor opens briefly and then closes.\n",TP);
      TP->force_me("peer prisoners 1");
    	return 1;
  	}
}