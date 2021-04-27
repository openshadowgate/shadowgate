//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall2");
  	set_exits(([
   	"north" : LROOMS+"wall3",
		"south" : LROOMS+"wall1"
	]));
}
