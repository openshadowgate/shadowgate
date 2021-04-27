//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("kitchen");
	set_short("kitchen");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
		"The kitchen is large and capable of serving large meals.  "+
		"This is not surprising with all the guards of the keep to "+
		"tend to.  There is three ovens along the south wall and a "+
		"large fireplace in the east wall.  Next to the ovens are "+
		"three stoves.  The center of the room is dominated by a large, "+
		"heavy wooden food preparation table.  Hanging from the ceiling "+
		"above the table are a various assortment of pots, pans, and other "+
		"cooking utensils.  Against the south wall are 2 wooden half-barrels "+
		"and an indoor well.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The aroma of fresh cooked meals fills the air.");
	set_listen("default","You hear liquids bubbling in pots on a stove.");
	set_items(([
		({"oven","ovens"}) : "These are large brick ovens with large iron "+
			"doors.  The ovens can easily bake several loaves of bread at the "+
			"same time, or even handle a whole hog.  The ovens look to be "+
			"fueled by wood.\n",
		({"stove","stoves"}) : "The stoves are for cooking things that are "+
			"normally cooked in skillets and pots.  The burners look large "+
			"enough to handle large sized pots.  The stoves look to be fueled "+
			"by wood.\n",
		"fireplace" : "The fireplace is a very wide on and has heavy rods "+
			"embedded into the floor at both ends of the firepit.  The rods "+
			"have a fork in the top and can hold another iron bar that can "+
			"support large iron kettles for heating water, or soups, or can be "+
			"used as a rotisserie.  The fireplace is long enough to handle a "+
			"side of beef.\n",
		({"barrels","barrel","half-barrels","half-barrel"}) : "The barrels are "+
			"filled with water, one soapy, one clear.  Some dirty dishes are "+
			"piled next to the barrel with the soapy water and clean dishes are "+
			"piled next to the one with the clear water\n",
		"well" : "This is a convenience for the kitchen workers since they will "+
			"not have to tote water from the outside.  It is, also, good for the "+
			"defense of the keep not to have your water source outside the walls.\n",
		({"pots","pans","utensils","pot","pan","untensil"}) : "Just what you'd "+
			"expect to find among the cooking untensils.  You were expecting "+
			"a +3 cleaver of cleaving?\n"
   ]));
  	set_exits(([
		"north" : LROOMS+"hall8"
	]));

  	set_door("door",LROOMS+"hall8","north","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens into a large hallway.\n");
   set_open("door",1);
}
