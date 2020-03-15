#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Road Through the Woods");
	set_long(
	"%^GREEN%^Road Through the Woods
%^GREEN%^This is a little %^CYAN%^road%^GREEN%^ through the %^BOLD%^%^BLACK%^C%^RESET%^%^CYAN%^haru %^BOLD%^%^BLACK%^M%^BLACK%^o%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^ta%^BOLD%^%^BLACK%^i%^RESET%^%^CYAN%^ns%^GREEN%^ that leads to the newly re-built city of Antioch. To the west you can see the gates of the city. To the northeast is the path leading back to the ruins of Antioch. The road is cobbled here and large %^CYAN%^stones%^GREEN%^ are set on either side of the road with runes carved into them telling of the great city of Antioch and blessing it with peace, luck, and wealth. To the southwest a road leads around the city into the mountains.\n"
	);
	set("night long",
	"%^GREEN%^Road Through the Woods
%^BLUE%^The peaks of the %^BOLD%^%^BLACK%^C%^RESET%^%^CYAN%^haru%^BLUE%^ Mountains are outlined by the moon. The forest seems less dangerous here for the gates of Antioch are just to your west and you can see by the light from their guard tower. Back to the northeast is the %^CYAN%^road%^BLUE%^ leading to the ruins of Antioch. That path seems more sinister, with the odd shadows from the %^CYAN%^t%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^ees%^BLUE%^ slithering across the road. Here the road is cobbled and the large %^CYAN%^s%^BOLD%^%^BLACK%^t%^BLACK%^o%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^BLUE%^ on either side of it are engraved with runes telling of the great city of Antioch and blessing it with peace, luck and wealth. To the southwest a road leads around the city.\n"
	);
	set_smell("default","You can smell the scents of a large city.");
	set_listen("default","You can hear the voices of the guards"+
	" up ahead.");
	set_items(([
	"mountains" : "The mountains extend as far as the eye can see.",
	({"road","little road","path","trail"}) : "The road is paved"+
	" with cobbled stones here and leads to the gates of Antioch.",
	({"stones","large stones"}) : "Large flat stones have been placed on either"+
	" side of the road and are engraved with runes telling of"+
	" Antioch's greatness and blessing peace, luck and wealth on"+
	" the city.",
	({"trees","tree","pines"}) : "The trees are thick and tall"+
	" but thin out up ahead where the city is.",
	]));
	set_exits(([
      "northeast" : ROOMS+"trail5",
      "northwest" : "/d/magic/temples/jarmila/jarmilaentry",
      "southwest" : "/d/antioch/greaterantioch/rooms/road/road1.c",
	"west" : ROOMS+"gates",
	]));
	set_pre_exit_functions(({"west"}),({"go_west"}));
}

int go_west()
{
	object obj;

	find_object_or_load("/d/antioch/antioch2/rooms/gates");
	"/d/antioch/antioch2/rooms/gates"->set_dir("west");
	return 1;
}
