//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LPOST;

void create(){
   ::create();
   set_name("post0");
  	set_exits(([
		"east" : LROOMS+"yard1",
		"up" : LROOMS+"tower1"
   ]));
}
void reset(){
	::reset();
	if(!present("monster")){
		new(LMON+"private_nm")->move(TO);
	}
}