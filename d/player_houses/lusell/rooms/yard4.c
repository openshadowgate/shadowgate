//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LYARD;

void create(){
   ::create();
   set_name("yard4");
  	set_exits(([
   	"southwest" : LROOMS+"yard1",
		"west" : LROOMS+"yard2",
		"east" : LROOMS+"drill_yard",
		"northwest" : LROOMS+"entry"
	]));
}