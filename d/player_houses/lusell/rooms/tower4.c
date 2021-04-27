//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower4");
  	set_exits(([
		"east" : LROOMS+"wall10",
		"south" : LROOMS+"wall9"
   ]));
}
