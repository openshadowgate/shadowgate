//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LPOST;

void create(){
   ::create();
   set_name("post6");
  	set_exits(([
		"south" : LROOMS+"hall4",
		"up" : LROOMS+"tower5"
   ]));
}
void reset(){
	::reset();
	if(!present("monster")){
		new(LMON+"private_nm")->move(TO);
	}
}