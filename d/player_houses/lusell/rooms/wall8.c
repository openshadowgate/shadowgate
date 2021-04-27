//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall8");
  	set_exits(([
   	"north" : LROOMS+"wall9",
		"south" : LROOMS+"wall7"
	]));
}
