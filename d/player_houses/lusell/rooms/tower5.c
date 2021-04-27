//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower5");
  	set_exits(([
  		"down" : LROOMS+"post6",
		"east" : LROOMS+"wall12",
		"west" : LROOMS+"wall11"
   ]));
}
