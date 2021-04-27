//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;

void create(){
	::create();
	set_name("cell");
   set_short("cell");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"This room is rather plain and lacks much "+
   	"in the way of extravagance.  There is a simple mat "+
   	"thrown onto the floor and a small basin of water "+
   	"rests beside it.  Otherwise, the stone walls are "+
   	"dull and dusty and the iron bar door is scratched, "+
   	"as if someone or something has been clawing at it.  "+
   	"It is cold and damp in here and breathing is difficult."
   );
  	set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_smell("default","Dirty bodies have slept in this room and you can "+
		"tell this by the smell.");
	set_listen("default","You hear an occassional tinkling of chains swaying "+
		"against one another.");
	set_items(([
		"mat" : "The mat doesn't look very comfortable to sit on, "+
			"but you're welcome to try.  It hasn't been refilled with "+
			"new straw in some time and it is old and stained.\n"
   ]));
   set_exits(([
		"out" : SROOMS+"torture"
  	]));

   new("/d/player_houses/daelmas/obj/gruel")->move(TO);
   new("/d/player_houses/daelmas/obj/twater")->move(TO);

   set_door("cell door",SROOMS+"torture","out","black skeleton key");
   set_locked("cell door",1,"lock");
   lock_difficulty("cell door", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");
   set_lock_description("cell door","lock","The lock is recessed and "+
   	"looks to be very intricate.");
   	(SROOMS+"torture")->set_locked("cell door",1,"lock");
   set_door_description("cell door","This door is made of very thick iron bars.\n");
   set_string("cell door","open","The door creaks open slowly to the torture chamber.\n");
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
  	if(str == "mat" || str == "on mat"){
   	tell_object(TP,"%^BOLD%^Your body aches as you try to get comfortable on "+
      	"the old mat.\n%^RESET%^");
      tell_room(TO,"%^BOLD%^"+TPQCN+" sighs and shifts uncomfortably "+
      	"as "+TP->query_subjective()+" sits on the mat.\n%^RESET%^",TP);
		return 1;
  	}
}