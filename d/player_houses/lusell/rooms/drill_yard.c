//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("drill_yard");
	set_short("practice yard");
	set_long(
    	"%^RESET%^%^GREEN%^"+
		"This is a large field.  A wooden rail fence is built through "+
		"the center so that a knight may practice at jousting.  Straw "+
		"targets sit against the wall in the south and wooden posts are "+
		"set into the ground to the east.  The field is all dirt and "+
		"grass otherwise and has been ridden over repeatedly during "+
		"practice sessions.  Guards can been seen drilling here at "+
		"all hours.  To the north there is a small building.\n"+
		"%^RESET%^"
   );
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells of dirt, sweat, and weapon oil.");
	set_listen("default","An occassional clank of armor can be heard nearby.");
	set_items(([
		({"straw targets","target","straw target","targets"}) : "Target with "+
			"bullseyes and targets that are crude representations of humanoid "+
			"forms are in the south.  Some of the targets have seen better days.\n",
		({"post","posts","wooden posts","wooden post"}) : "The posts are about "+
			"ten inches in diameter and are set firmly in the ground.  Numerous "+
			"slash and cut marks are found on the posts.\n",
		({"fence","wooden fence","wooden rail fence"}) : "The fence runs north "+
			"to south along the center of the practice field.  The fence is long "+
			"enough for a horse to gain full speed by the center of the length "+
			"of the fence.  Formal jousts are done this way with each knight "+
			"charging at the other along their own side of the fence.\n"
   ]));
  	set_exits(([
   	"west" : LROOMS+"yard4",
		"north" : LROOMS+"armory"
	]));

  	set_door("door",LROOMS+"armory","north","ruby key");
   set_door_description("door","This is a simple wooden door.\n");
   set_string("door","open","The door into a room smelling of "+
   	"weapon oil and metal.\n");
   set_locked("door",0,"lock");
	(LROOMS+"armory")->set_locked("door",0,"lock");
}
