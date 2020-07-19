#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Cherry Street");
	set_long(
	"You are on Cherry street.\n"+
	"A little further to the east is a very large and impressive"+
	" stone church. Right outside the church Cherry street"+
	" is joined by Crescent street from the southwest and Cedar"+
	" street from the northwest. To the west are several shops,"+
	" the weapons shop and armory are directly to the west and"+
	" not far past them you can see a bank, near the large"+
	" fountain." 
	);
	set("night long",
	"You are on Cherry street.\n"+
	"The street lights along the road help guide your way. To"+
	" the east there is a large church with a great stone archway"+
	" that spills inviting yellow light out onto the cold streets."+
	" Outside the church is the intersection of Cherry street"+
	" with Crescent and Cedar. Crescent streets travels southwest"+
	" while Cedar runs to the northwest. Straight west of you"+
	" Cherry street continues. It is the main street in town"+
	" and there are many shops along it, though all but the bank"+
	" appear closed at this time of night. A large fountain sits"+
	" in the center of the street, where Oak joins Cherry street."
	);
	set_smell("default","The scent of polish hangs in the air"+
	" here.");
	if(query_night() == 1) {
		set_listen("default","You hear the faint gurgle of the"+
		" fountain.");
	}
	else {
		set_listen("default","The street is alive with shoppers"+
		" arguing over prices.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cherry street.",
	"fountain" : "A large fountain is in the center of the Cherry"+
	" street.",
	"church" : "There is a very impressive stone church to the"+
	" east.",
	]));
	set_exits(([
	"west" : ROOMS+"street20",
	"east" : ROOMS+"street14",
	]));
}
