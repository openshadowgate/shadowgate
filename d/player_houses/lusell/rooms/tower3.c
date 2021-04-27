//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LTOWER;

void create(){
   ::create();
   set_name("tower3");
  	set_exits(([
   	"down" : LROOMS+"post4",
		"north" : LROOMS+"wall7",
		"south" : LROOMS+"wall6"
   ]));
}
