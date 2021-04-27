//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall3");
  	set_exits(([
   	"north" : LROOMS+"wall4",
		"south" : LROOMS+"wall2"
	]));
}
