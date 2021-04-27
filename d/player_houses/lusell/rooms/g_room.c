//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("g_room");
	set_short("guest room");
	set_long(
    	"%^RESET%^%^CYAN%^"+
		"This is a small room with a bed.  The room looks very "+
		"utilitarian.  The bed if covered with a wool blanket and "+
		"a down-filled comforter is folded at the foot of the bed.  "+
		"There is a wooden chest for storing gear on the west wall "+
		"and a small table with a basin and ewer of water for "+
		"refreshing yourself.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room smells clean and sterile.");
	set_listen("default","The room is very quiet.");
	set_items(([
		"bed" : "The bed is large enough for two people of human size.  "+
			"The bedding consists of a sleeve filled with straw and placed "+
			"on a wooden pallet.  The is covered by a wool blanket and a "+
			"down-filled comforter is folded neatly at the end of the bed.  "+
			"The straw in the matress shows evidence that it is replaced regularly.\n",
		({"wooden chest","chest"}) : "The chest is rectangular, made of wood, and "+
			"will store a guests items.\n",
		"table" : "The table is small and simple holding only a wash basin and "+
			"ewer on its top.\n",
		({"ewer","basin","wash basin"}) : "These devices are used to refresh "+
			"oneself when they awake.  The ewer is always filled with fresh water "+
			"and the basin is clean and dry.  Under the basin is a small towel "+
			"folded neatly.\n"
   ]));
  	set_exits(([
		"north" : LROOMS+"hall6"
	]));

  	set_door("door",LROOMS+"hall6","north","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens into a large hallway.\n");
}
