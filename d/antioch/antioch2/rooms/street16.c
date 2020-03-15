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
	set_short("Crescent Street");
	set_long(
	"You are on Crescent street.\n"+
	"To the northeast Crescent street continues to join with"+
	" Cherry and Cedar outside of the large church. It also"+
	" continues to the southwest, meeting with Pine street not"+
	" far from the Antioch gates. On the southern side of the"+
	" road there is a small house with a brown roof. There"+
	" appears to be an entrance to it a little further down this"+
	" street."
	);
	set("night long",
	"You are on Crescent street.\n"+
	"The street light here bathes this part of the street"+
	" with warm yellow light. On the southern side of the road"+
	" here there is a little house. It is probably a shop of"+
	" some sort, and you can smell the faint scent of dried"+
	" meat in the air. It looks like the entrance to it is"+
	" just a bit further down on this street. Past the door to"+
	" the shop Crescent joins with Pine, not very far from the"+
	" Antioch gates. This street also runs to the northwest,"+
	" leading you to the church."
	);
	set_smell("default","You smell the faint scent of dried"+
	" food.");
	if(query_night() == 1) {
		set_listen("default","It's fairly quiet at this time of"+
		" night.");
	}
	else {
		set_listen("default","You can hear the sounds of a busy"+
		" city.");
	}
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Crescent street.",
	({"house","building","shop"}) : "It is a small little wooden"+
	" house with a pretty brown roof. The entrance is a little"+
	" southwest of here.",
	"church" : "There is a very impressive stone church to the"+
	" northeast.",
	]));
	set_exits(([
	"southwest" : ROOMS+"street17",
	"northeast" : ROOMS+"street15",
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
