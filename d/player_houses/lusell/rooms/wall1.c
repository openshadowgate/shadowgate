//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall1");
  	set_exits(([
   	"north" : LROOMS+"wall2",
		"east" : LROOMS+"wall0"
	]));
}
