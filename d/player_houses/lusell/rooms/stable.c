//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("stable");
	set_short("stable");
	set_long(
    	"%^RESET%^%^GREEN%^"+
		"The stables are large and will hold several horses at once.  "+
		"You count no less than twenty individual stalls and one larger "+
		"holding area for horses to be exercised in.  Tack hangs from the "+
		"southern wall and barding and saddles rest over saw horses.  The straw "+
		"covering the floor is clean as are the stalls.  Barrels of feed "+
		"and water line the northern wall and a smithy can be seen in the "+
		"northwest.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells of straw and horses.");
	set_listen("default","You hear the movement of horses nearby.");
	set_items(([
		({"stall","stalls"}) : "These are small rectangular rooms "+
			"in which a horse can be placed and a gate closed behind "+
			"it.  The stall has a place for horse feed and water and "+
			"the floor is covered with straw that is changed regularly "+
			"to keep the horse from fouling itself.  The horse has just "+
			"enough room to turn around.\n",
		"tack" : "Tack consists of harnesses, bits, reins, and bridles.  "+
			"Items normally associated with controlling horses.\n",
		({"barding","saddles","saddle"}) : "Barding is equipment used to "+
			"armor or decorate horses.  You find various types from leathers "+
			"to plate.  Saddles are also resting here and all items look to "+
			"have been recently polished and oiled.\n",
		({"barrels","barrel"}) : "Horse feed and water...what did you expect?\n"
   ]));
  	set_exits(([
                "west" : LROOMS + "tethering",
		"north" : LROOMS+"smithy",
		"east" : LROOMS+"yard2"
	]));

  	set_door("gates",LROOMS+"yard2","east","ruby key");
   set_door_description("gates","Simple wooden gates.\n");
   set_string("gates","open","The gates open to the cobblestone courtyard.\n");
}
