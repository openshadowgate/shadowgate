//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall13");
  	set_exits(([
   	"west" : LROOMS+"wall12",
		"east" : LROOMS+"tower6"
	]));
}
