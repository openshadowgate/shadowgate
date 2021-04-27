//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall14");
  	set_exits(([
   	"south" : LROOMS+"wall15",
		"north" : LROOMS+"tower6"
	]));
}
