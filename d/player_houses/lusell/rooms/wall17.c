//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall17");
  	set_exits(([
   	"north" : LROOMS+"wall16",
		"south" : LROOMS+"wall18"
	]));
}
