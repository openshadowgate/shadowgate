//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LPOST;

void create(){
   ::create();
   set_name("post2");
  	set_exits(([
		"east" : LROOMS+"hall0"
   ]));
}
void reset(){
	::reset();
	if(!present("monster")){
		new(LMON+"private_nm")->move(TO);
	}
}