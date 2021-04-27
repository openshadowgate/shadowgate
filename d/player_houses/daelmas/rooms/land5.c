//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Fifth landing");
   set_short("fifth landing");
   set_long(
   	"%^RESET%^"+
   	"You take a deep breath, unsure if you can climb yet "+
   	"another step. A torch lights the stairway as it continues "+
   	"its ascension upwards. There are also wooden doors to the "+
   	"left and right of you.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
	]));

   set_door("door",DROOMS+"study","east","marble key");
   set_locked("door",1,"lock");
   (DROOMS+"study")->set_locked("door",1,"lock");
   set_door_description("door","The door is made of polished oak.");
   set_string("door","open","You open the door into a study.\n");

   set_exits(([
		"up" : DROOMS+"land6",
		"down" : DROOMS+"land4",
		"east" : DROOMS+"study"
	]));
}