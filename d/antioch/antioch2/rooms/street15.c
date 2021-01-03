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
	"%^WHITE%^On your east is part of a large building, it looks like a %^ORANGE%^ch%^BOLD%^%^WHITE%^u%^WHITE%^r%^RESET%^%^ORANGE%^ch.%^WHITE%^ It has been recently constructed from perfectly cut stone blocks and spans several stories in height. It is very well built and many people must have joined together in its creation. Directly north of here there appears to be an entrance to it on the eastern side, at the intersection of Crescent, Cherry, and Cedar street. %^MAGENTA%^Cherry street%^RESET%^runs straight west through the main part of town. Cedar street runs off to the northwest, and Crescent runs to the southwest towards the Antioch gates.
"
	);
	set_smell("default","A faint scent of incense hangs in the"+
	" breeze.");
	set_listen("default","You can hear muffled prayers from"+
	" within the church.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Crescent street.",
	"church" : "The church is to your west, you can see the"+
	" entrance straight north of here. It is a few stories in"+
	" height and appears to be newly built.",
	]));
	set_exits(([
	"north" : ROOMS+"street14",
	"southwest" : ROOMS+"street16",
	]));
}
