//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Room of Skulls");
   set_short("room of skulls");
   set_long(
   	"%^BOLD%^%^RED%^"+
   	"You have come to the end of the hallway. The same "+
   	"%^RESET%^%^RED%^copper %^BOLD%^and %^RESET%^%^ORANGE%^brass "+
   	"shelves %^BOLD%^%^RED%^line the side-walls and this part of "+
   	"it looks little different then any other, except for the large "+
   	"bare wall in front of you.  This wall is made of the same "+
   	"material as the rest of the hallway, an oddly metallic looking "+
   	"%^BLACK%^grey stone%^RED%^. A few feet in front of the wall "+
   	"rests a %^RESET%^%^RESET%^%^ORANGE%^light brown%^BOLD%^%^RED%^, "+
		"%^RESET%^%^ORANGE%^wooden desk%^BOLD%^%^RED%^. Behind the "+
		"desk is a chair made of %^RESET%^bone%^BOLD%^%^RED%^.%^RESET%^\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","The dusty smell that covered the rest of the "+
   	"hallway is absent here.");
   set_listen("default","The rhythmic dripping blood still sounds "+
   	"throughout the corridor.");
   set_items(([
   	"ceiling" : "The ceiling is not visible, just a patch of darkness.\n",
   	({"shelves","shelf"}) : "The shelves are old. They are made of a "+
   		"mix of copper and brass and look rusted in some places. "+
   		"The shelves themselves are so large it is difficult to "+
   		"see the back. Slender, tarnished silver poles hold the "+
   		"shelves up and each shelf is just a flat slab of metal.\n",
		({"skull","skulls"}) : "There are thousands of skulls from numerous "+
			"creatures, some easily recognizable, others so foreign "+
			"and exotic it is impossible to tell what they are.\n",
		"blood" : "Blood drips down from the blackness, where the "+
			"ceiling would be. It seems to be normal blood, from "+
			"a human or demi-human. Strangely it disappears whenever "+
			"it touches it something.\n",
		"desk" : "The desk is a walnut brown wood, and seems to have "+
			"no drawers. There is nothing on the desk.\n",
		"chair" : "The chair is made of the bones from arms and legs of "+
			"elves. Two skulls at attached to the end of the armrest, "+
			"their empty eye sockets staring at whoever is sitting "+
			"opposite the desk.\n"
	]));

   set_exits(([
		"north" : DROOMS+"hblood3"
	]));
}
void init() {
  	::init();
  	add_action("sit","sit");
}
int sit(string str) {
   if(!str) {
     	tell_object(TP,"Sit where?");
     	return 1;
   }
  	if(str == "chair" || str == "on chair"){
     	tell_object(TP,"%^BOLD%^%^RED%^You sit on the chair made of "+
     		"bones and feel a terrible power sweep over you.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" sit down in the chair of bones "+
        	"and a terrible smile plays "+
        	"over "+TP->query_possessive()+" face.\n%^RESET%^",TP);
		return 1;
  	}
}
