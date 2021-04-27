//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall5");
  	set_exits(([
   	"north" : LROOMS+"wall6",
		"south" : LROOMS+"wall4"
	]));
}
