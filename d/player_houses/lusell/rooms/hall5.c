//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall5");
  	set_exits(([
		"south" : LROOMS+"barracks",
		"north" : LROOMS+"officerq",
		"east" : LROOMS+"hall6",
		"west" : LROOMS+"post4"
   ]));

  	set_door("north door",LROOMS+"officerq","north","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("north door","open","The door opens to the officer's quarters.\n");
   set_locked("north door",0,"lock");
		(LROOMS+"officerq")->set_locked("north door",0,"lock");

  	set_door("south door",LROOMS+"barracks","south","ruby key");
   set_door_description("south door","A simple wooden door.\n");
   set_string("south door","open","The door opens to the barracks.\n");
   set_locked("south door",0,"lock");
		(LROOMS+"barracks")->set_locked("south door",0,"lock");
   set_open("south door",1);
   	(LROOMS+"barracks")->set_open("south door",1);
}
