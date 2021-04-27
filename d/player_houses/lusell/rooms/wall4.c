//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall4");
  	set_exits(([
   	"north" : LROOMS+"wall5",
		"south" : LROOMS+"wall3"
	]));
}
