//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall10");
  	set_exits(([
   	"west" : LROOMS+"tower4",
		"east" : LROOMS+"wall11"
	]));
}
