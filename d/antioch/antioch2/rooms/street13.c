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
	set_short("Cedar Street");
	set_long(
	"You are on Cedar street.\n"+
	"On the east is a very large, newly built church. It stretches"+
	" up a few stories in height. The entrance to it is a little"+
	" south from here, at the intersection of Cedar, Crescent,"+
	" and Cherry street. Cherry street is the main street through"+
	" town, it has most of the shops on it, along with the bank."+
	" Crescent street runs along the southwest, heading back"+
	" towards the town gates. Cedar continues to the northwest,"+
	" and there appears to be a shop along the way." 
	);
	set("night long",
	"You are on Cedar street.\n"+
	"The surrounding street lights help to keep the street fairly"+
	" well lit at night. Directly to the east is a large church"+
	" that looks to be fairly new. It stretches up several"+
	" stories in height and looks quite impressive. The entrance"+
	" is a little further south from here, at the intersection"+
	" of Cedar, Crescent, and Cherry. Crescent street continues"+
	" down to the southwest, while Cedar runs up to the northwest."+
	" Cherry street runs straight west and is the main street"+
	" through town, having most of the shops on it."
	);
	set_smell("default","A light scent of incense is in the air.");
	set_listen("default","Soft prayers can be heard from the"+
	" church.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cedar street.",
	"church" : "The church is to your west, you can see the"+
	" entrance directly south of here. It is a few stories in"+
	" height and appears to be newly built.",
	]));
	set_exits(([
	"northwest" : ROOMS+"street12",
	"south" : ROOMS+"street14",
	]));
}
