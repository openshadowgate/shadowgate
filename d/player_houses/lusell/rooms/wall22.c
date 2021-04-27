//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall20");
  	set_exits(([
   	"east" : LROOMS+"wall21",
		"west" : LROOMS+"tower2"
	]));

  	set_door("door",LROOMS+"tower2","west","ruby key");
   set_door_description("door","The door is made "+
   	"of stout oak and bound in heavy bars of iron.  The door "+
   	"has deep scars as if it had repelled prospective invaders "+
   	"at least once before.\n");
   set_string("door","open","The doors open into an archers tower.\n");
}
