//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall12");
  	set_exits(([
   	"west" : LROOMS+"tower5",
		"east" : LROOMS+"wall13"
	]));
}
