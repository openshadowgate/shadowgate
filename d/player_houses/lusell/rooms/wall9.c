//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall9");
  	set_exits(([
   	"north" : LROOMS+"tower4",
		"south" : LROOMS+"wall8"
	]));
}
