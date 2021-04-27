//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

int FLAG;

void create(){
   ::create();
   set_name("to_tonovi");
	set_short("road to keep");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
		"The road leads north to a large imposing keep and south "+
		"back to the town of Tonovi.  You can see that the keep is "+
		"surrounded by a moat and crossing the moat will be no easy task.  "+
		"The road to the keep is lined by large white stones.\n"+
		"%^RESET%^"
   );
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","Smells of the city reach you here.");
	set_listen("default","Noises from the keep to the north mingle "+
		"with the noises of the city.");
	set_items(([
   ]));
  	set_exits(([
		"north" : LROOMS+"bridge",
		"south" : "/d/dagger/tonovi/2path2"
	]));

	set_search("stones","You look over the large stones carefully and "+
		"notice they are all different and all the alike at the same "+
		"time.  Some stones are jagged, some squared and some rounded, "+
		"but they have all been painted white.\n");
	set_search("round stones","There is only one rounded stone.\n");
	set_search("jagged stones","You discern nothing special about these stones.\n");
	set_search("squared stones","You discern nothing special about these stones.\n");
	set_search("round stone","This stone is smaller than most of the others and "+
		"might be able to be moved.\n");
	FLAG = 0;
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}
void init() {
  	::init();
  	add_action("lift_em","lift");
}
int GoThroughDoor(){
   if(!userp(TP)) return 0;
   return 1;
}
int lift_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Lift what?");
      return 1;
   }
	if(str == "round stone"){
		if(FLAG == 1){
			tell_object(TP,"%^BOLD%^There is nothing under the "+
				"stone, someone must have pinched your stashed key.\n");
			return 1;
		}else{
			tell_object(TP,"%^BOLD%^You find your spare key just where you left it.\n");
			tell_room(TO,"%^BOLD%^"+TPQCN+" messes around by the stones.\n",TP);
			FLAG = 1;
			new(LOBJ+"ruby_key")->move(TO);
			return 1;
		}
	}
}
void reset(){
   ::reset();
  	FLAG = 0;
}