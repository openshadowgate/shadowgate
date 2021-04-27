//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall6");
  	set_exits(([
   	"north" : LROOMS+"tower3",
		"south" : LROOMS+"wall5"
	]));
}
