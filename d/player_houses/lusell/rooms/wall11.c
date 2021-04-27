//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall11");
  	set_exits(([
   	"west" : LROOMS+"wall10",
		"east" : LROOMS+"tower5"
	]));
}
