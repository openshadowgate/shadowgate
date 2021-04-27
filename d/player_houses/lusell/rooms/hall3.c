//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall3");
  	set_exits(([
		"north" : LROOMS+"hall4",
		"south" : LROOMS+"hall2",
		"east" : LROOMS+"dining",
		"west" : LROOMS+"sanctuary"
   ]));

  	set_door("door",LROOMS+"dining","east","ruby key");
   set_door_description("door","The door is made from black walnut "+
   	"and has elaborate carvings about the lintel.\n");
   set_string("door","open","The door opens to an ornate dining hall.\n");
   set_locked("door",0,"lock");
		(LROOMS+"dining")->set_locked("door",0,"lock");
   set_open("door",1);
   	(LROOMS+"dining")->set_open("door",1);
}
