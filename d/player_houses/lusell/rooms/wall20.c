//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall20");
  	set_exits(([
   	"north" : LROOMS+"wall19",
		"south" : LROOMS+"wall21"
	]));
}
