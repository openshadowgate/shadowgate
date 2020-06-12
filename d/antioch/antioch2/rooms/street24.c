#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
   object ob;
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Oak Street");
	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze. There used to be an inn to the west and a bar to the east, but they now lay wrecked. There was a palace to the north but entire buildings have crumbled to the ground here, blocking your path in that direction.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Oak street.",
	"palace" : "At the northern part of this road is a large and"+
	" impressive palace.",
	"inn" : "The inn is the large two story building on the east,"+
	" the entrance is right here and it looks like a clean and upright"+
	" establishment. There is a sign hanging outside of it with a picture"+
	" of a white dragon on it.",
	({"bar","tavern"}) : "The entrance to the local tavern is on the"+
	" west here. A sign hangs out in front of it, declaring it the Eagle's Roost.",
	"fountain" : "You can barely make out what looks like a large"+
	" fountain at the southern end of this street.",
	]));
	set_exits(([
	//"north" : ROOMS+"street25",
	"south" : ROOMS+"street10",
	//"west" : ROOMS+"bar",
	//"east" : ROOMS+"inn1",
	]));
	set_door("door",ROOMS+"inn1","east",0);
/**************
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id(({"board","bulletin board", "reality board"}));
   ob->set_board_id("main_board");
  ob->set_ooc_board(1);
   ob->set_short("The ShadowGate Reality Board");
   ob->set_long("An old cork board where the adventurers who pass through ShadowGate post information on the reality they have discovered.\n");
   ob->set_max_posts(50);
   ob->set_location("/d/antioch/antioch2/rooms/street24");
****************************/
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/inn1"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/inn1"->set_open("door",1);
	}
   find_object_or_load("/d/npc/nulipseas");
   find_object_or_load("/d/npc/whitson");
   find_object_or_load("/d/npc/swarmani");
}
