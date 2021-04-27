//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall7");
  	set_exits(([
		"east" : LROOMS+"hall8",
		"west" : LROOMS+"hall2"
   ]));
}
