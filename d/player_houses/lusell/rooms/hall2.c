//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall2");
  	set_exits(([
		"north" : LROOMS+"hall3",
		"south" : LROOMS+"hall1",
		"east" : LROOMS+"hall7",
		"west" : LROOMS+"hall6"
   ]));
}
