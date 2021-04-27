//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall0");
  	set_exits(([
   	"west" : LROOMS+"post2",
		"east" : LROOMS+"post3",
		"north" : LROOMS+"hall1",
		"south" : LROOMS+"entry"
   ]));

  	set_door("double doors",LROOMS+"entry","south","ruby key");
   set_door_description("double doors","The double doors are made "+
   	"of stout oak and bound in heavy bars of iron.  The doors "+
   	"have deep scars as if they had repelled prospective invaders "+
   	"at least once before.\n");
   set_string("double doors","open","The doors open wide to a set "+
   	"of wide stairs leading down into the courtyard to the south.\n");

	if(random(2)){
		switch(random(1)){
			case (0):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"sergeant"));
  				break;
  			case (1):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  			default :
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  		}
  	}				
}
