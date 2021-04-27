//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Fourth landing");
   set_short("fourth landing");
   set_long(
   	"%^RESET%^"+
   	"Surely you must be nearing the top of the tower now. A "+
   	"torch lights the stairway as it continues its ascension "+
   	"upwards. There are also wooden doors to the left and right of you.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The air is clean and smells faintly of flowers.");
   set_listen("default","You hear hushed whispers from somewhere within the tower.");
   set_items(([
	]));

   set_door("door",DROOMS+"mast_room","west","marble key");
   set_locked("door",1,"lock");
   lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");
   (DROOMS+"mast_room")->set_locked("door",1,"lock");
   set_door_description("door","The door is made of magnificently polished oak.");
   set_string("door","open","You open the door into a master bedroom.\n");

   set_exits(([
		"up" : DROOMS+"land5",
		"down" : DROOMS+"land3",
		"west" : DROOMS+"mast_room"
	]));
}