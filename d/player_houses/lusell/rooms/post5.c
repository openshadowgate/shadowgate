//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LPOST;

void create(){
   ::create();
   set_name("post5");
  	set_exits(([
		"west" : LROOMS+"hall8",
		"up" : LROOMS+"tower7"
   ]));
}
void reset(){
	::reset();
	if(!present("monster")){
		new(LMON+"private_nm")->move(TO);
	}
}