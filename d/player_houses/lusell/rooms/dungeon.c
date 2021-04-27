//Coded by Diego//
//Updated by Circe 1/29/04

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("dungeon");
	set_short("dungeon");
	set_long(
    	"%^BOLD%^%^BLACK%^"+
		"This room is nice and quiet.  Chains dangle from the wall "+
		"ominously and in the middle of the room is a "+
		"%^RESET%^%^ORANGE%^rough hewn oak table %^BOLD%^%^BLACK%^with "+
		"%^RESET%^%^ORANGE%^leather restraints %^BOLD%^%^BLACK%^at each end.  "+
		"Hanging on the south wall hand implements such as pliers, clamps, "+
		"whips, and of course the more pointy objects as well as the pokers "+
		"for the %^RED%^fire%^BLACK%^.  Next to the implements is a "+
		"%^YELLOW%^censer %^BLACK%^and a %^RED%^brazier%^BLACK%^.  "+
		"A bucket of coal in on the floor next to them.\n"+ 
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room smells of sweat and fear.");
	set_listen("default","The room is very quiet at the moment.");
	set_items(([
		"table" : "The table is not made for comfort apparently.  The wood "+
			"has not been finished and is full of splinters.  The leather "+
			"straps at each end fit through holes and can securely fasten a "+
			"person's hands above their head as well as a strap that goes "+
			"about the throat to immobilize the head.  There are straps at "+
			"the other end, obviously, intended for the ankles.\n",
	({"tongs","clamps","pliers","whips","implements","pokers","pointy objects"}) : "Come "+
		"now, do I really need to elaborate on what these are for?  A slight "+
            "open space seems to be on the north wall.\n",
		"censer" : "This is a dish on a stand used for burning incense.\n",
		"brazier" : "The device will hold burning coals and, also, the pokers "+
			"that will be eventually heated to red hot in them.\n",
            ({"wall","north wall"}) : "There seems to be an open space.  Perhaps "+
               "something is missing?",
   ]));
   set_search("default","Amid all the strange devices, there seems to be a small opening on the north wall.");
   set_search("north wall","Searching the north wall, you find a small lever in the opening that was cleverly hidden.");
  	set_exits(([
	]));
}
void init() {
  ::init();
  add_action("pull_em","pull");
}
int pull_em(string str) {
	if(!str) {
   	tell_object(TP,"Pull what?");
      return 1;
  	}
  	if(str == "lever"){
   	if(member_array("up",TO->query_exits()) != -1) {
     		tell_object(TP,"You pull the lever until you hear a click!\n"+
     			"A portion of the ceiling slides closed.\n");
     		tell_room(ETP,""+TPQCN+" pulls the lever and a portion of the "+
     			"ceiling slides closed.\n",TP);
     		remove_exit("up");
			tell_room((LROOMS+"lusell"),"%^BOLD%^A portion of the floor in "+
				"the northwest slides closed.");	
     		(LROOMS+"lusell")->remove_exit("down");
         return 1;
      }
     	tell_object(TP,"You pull the lever until you hear a click!\n"+
     		"A portion of the ceiling slides open.\n");
     	tell_room(ETP,""+TPQCN+" pull the lever and a portion of the "+
     		"ceiling slides open.\n",TP);
     	add_exit(LROOMS+"lusell","up");
		tell_room((LROOMS+"lusell"),"%^BOLD%^A portion of the floor in "+
			"the northwest slides open.");
     	(LROOMS+"lusell")->add_exit(LROOMS+"dungeon","down");
     	return 1;
	}
}