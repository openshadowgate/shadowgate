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
	set_short("Pine Street");
	set_long(
	"You are on Pine street.\n"+
	"To the north is the intersection of Pine with Apple and"+
	" Cherry. There is also a sign with the symbol of a stables"+
	" on it, hanging over the doorway of a building on the west"+
	" side. To the east of that Cherry street continues into the"+
	" main part of town. Apple street runs off to the northeast."+
	" To the southwest Pine street continues back to intersect"+
	" with Crescent."
	);
	set("night long",
	"You are on Pine street.\n"+
	"Street lights to the north and southeast shed light enough"+
	" light for you to easily see by. To the southeast Pine runs"+
	" down to meet with Crescent. To the north there is an"+
	" intersection with Cherry and Apple street. There is also"+
	" a sign hanging above the doorway to a building on the"+
	" west up ahead with the symbol of a stables. Cherry street"+
	" runs east, away from it and to the main part of town. Apple"+
	" street runs to the northeast."
	);
	set_smell("default","You smell the scent of horses.");
	set_listen("default","The sounds of horses stomping about"+
	" in their stalls drifts in from the north.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Pine Street.",
	"sign" : "There is a wooden sign to the north with the"+
	" symbol of a stables on it.",
	]));
	set_exits(([
	"north" : ROOMS+"street6",
	"southeast" : ROOMS+"street4",
	]));
}
