//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall8");
  	set_exits(([
		"east" : LROOMS+"post5",
		"west" : LROOMS+"hall7",
		"south" : LROOMS+"kitchen"
   ]));

  	set_door("door",LROOMS+"kitchen","south","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens to the kitchen.\n");
   set_locked("door",0,"lock");
		(LROOMS+"kitchen")->set_locked("door",0,"lock");
   set_open("door",1);
   	(LROOMS+"kitchen")->set_open("door",1);
}
