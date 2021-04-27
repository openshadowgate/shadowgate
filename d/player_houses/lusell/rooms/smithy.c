//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("smithy");
	set_short("black smith's shop");
	set_long(
    	"%^RESET%^%^RED%^"+
		"The black smith's work area is covered with soot and "+
		"smells of smoke.  This area is hot and oppressive owing to "+
		"the fact that the furnace is stoked and kept hot so that "+
		"the smith may apply his trade.  A large black anvil dominates "+
		"the center of the room and a furnace is against the west wall.  "+
		"Raw iron ore sits in bins as well as billets piled in the "+
		"south awaiting to become a weapon or horse shoes.  A huge "+
		"wooden barrel of water sits next to the anvil.  Hammers, "+
		"tongs, and other tools of the smiths trade hang from the "+
		"rafters near the anvil.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells of smoke and horse manure.");
	set_listen("default","You hear the movement of horses nearby "+
		"and the roaring fire in the furnace.");
	set_items(([
		({"tool","tools","hammer","tongs"}) : "Tools use by the "+
			"smithy hang awaiting use.  While the area is soot covered, "+
			"the tools are in excellent shape.\n",
		({"bins","iron ore","billets","billet"}) : "The bins contain "+
			"materials used by a smithy in making steel and iron items as "+
			"needed.  Near the bins are billets.  Billets are blocks of "+
			"steel, iron or other metal waiting shaping into a usable form.\n",
		"anvil" : "The anvil is huge and serves as the work surface for "+
			"the blacksmith in forming the metals of his trade into usable "+
			"items.  The anvil looks like it would be impossible to lift, but "+
			"even so it is affixed the the ground with huge spikes.\n",
		({"water","barrel","barrel of water"}) : "The barrel of water sits "+
			"next to the anvil so that the smithy will be able to quench the "+
			"metals he works on without moving very far from the anvil.\n"
   ]));
  	set_exits(([
		"south" : LROOMS+"stable"
	]));
	set_property("smithy",1);
}
