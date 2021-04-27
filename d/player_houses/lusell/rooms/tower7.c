//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower7");
  	set_exits(([
  		"down" : LROOMS+"post5",
		"south" : LROOMS+"wall16",
		"north" : LROOMS+"wall15"
   ]));
}
