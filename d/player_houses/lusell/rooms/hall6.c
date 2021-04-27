//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall6");
  	set_exits(([
		"east" : LROOMS+"hall2",
		"west" : LROOMS+"hall5",
		"south" : LROOMS+"g_room"
   ]));

  	set_door("door",LROOMS+"g_room","south","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens to the small bedroom.\n");
   set_locked("door",0,"lock");
		(LROOMS+"g_room")->set_locked("door",0,"lock");
}
