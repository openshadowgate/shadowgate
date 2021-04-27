//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
  	::create();
   set_name("Second landing");
   set_short("second landing");
   set_long(
   	"%^RESET%^"+
   	"You begin to grow tired from climbing the tower and are quite "+
   	"relieved to rest at this landing. A torch lights the stairway "+
   	"as it continues its ascension upwards. There are also wooden "+
   	"doors to the left and right of you.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
	]));

  	set_door("eastern door",DROOMS+"wash_room","east","marble key");
  	set_locked("eastern door",1,"lock");
  	set_lock_description("eastern door","lock","The lock is recessed and "+
  		"looks to be very intricate.");
	(DROOMS+"wash_room")->set_locked("eastern door",1,"lock");
  	set_door_description("eastern door","The door is made of polished oak.");
  	set_string("eastern door","open","You open the door to the washroom.\n");

  	set_door("western door",DROOMS+"kitchen","west","marble key");
  	set_locked("western door",1,"lock");
	(DROOMS+"kitchen")->set_locked("western door",1,"lock");
  	set_door_description("western door","The door is made of polished oak.");
  	set_string("western door","open","You open the door into the kitchen.\n");

  	set_exits(([
		"east" : DROOMS+"wash_room",
		"up" : DROOMS+"land3",
		"down" : DROOMS+"foyer",
		"west" : DROOMS+"kitchen"
	]));
}