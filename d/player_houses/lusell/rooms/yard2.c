//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LYARD;

void create(){
   ::create();
   set_name("yard2");
  	set_exits(([
   	"southeast" : LROOMS+"yard1",
		"west" : LROOMS+"stable",
		"east" : LROOMS+"yard3",
		"northeast" : LROOMS+"entry"
	]));

  	set_door("gates",LROOMS+"stable","west","ruby key");
   set_door_description("gates","Simple wooden gates.\n");
   set_string("gates","open","The gates open to the stable.\n");
   set_locked("gates",0,"lock");
		(LROOMS+"stable")->set_locked("gates",0,"lock");
   set_open("gates",1);
   	(LROOMS+"stable")->set_open("gates",1);
}
