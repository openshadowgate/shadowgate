//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall7");
  	set_exits(([
   	"north" : LROOMS+"wall8",
		"south" : LROOMS+"tower3"
	]));
}
