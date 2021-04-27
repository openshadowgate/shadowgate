//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall15");
  	set_exits(([
   	"south" : LROOMS+"tower7",
		"north" : LROOMS+"wall14"
	]));
}
