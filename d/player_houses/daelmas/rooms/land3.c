//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Third landing");
   set_short("third landing");
   set_long(
   	"%^RESET%^"+
   	"You've reached the third floor of the tower. A torch lights "+
   	"the stairway as it continues its ascension upwards. There are "+
   	"also wooden doors to the left and right of you.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
	]));

   set_door("western door",DROOMS+"gab_room","west","marble key");
   set_locked("western door",1,"lock");
   (DROOMS+"gab_room")->set_locked("door",1,"lock");
   set_door_description("western door","The door is made of polished oak.");
   set_string("western door","open","You open the door into a bedroom.\n");

  	set_door("eastern door",DROOMS+"dael_room","east","marble key");
   set_locked("eastern door",1,"lock");
   (DROOMS+"dael_room")->set_locked("door",1,"lock");
   set_door_description("eastern door","The door is made of polished oak.");
   set_string("eastern door","open","You open the door into a bedroom.\n");

   set_exits(([
		"up" : DROOMS+"land4",
		"down" : DROOMS+"land2",
		"west" : DROOMS+"gab_room",
		"east" : DROOMS+"dael_room"
	]));
}