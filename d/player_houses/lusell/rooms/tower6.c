//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower6");
  	set_exits(([
		"south" : LROOMS+"wall14",
		"west" : LROOMS+"wall13"
   ]));
}
