//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall19");
  	set_exits(([
   	"north" : LROOMS+"wall18",
		"south" : LROOMS+"wall20"
	]));
}
