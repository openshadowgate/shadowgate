//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall1");
  	set_exits(([
		"north" : LROOMS+"hall2",
		"south" : LROOMS+"hall0"
   ]));
}
