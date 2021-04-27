// BWANA Fortress

#include <std.h>
#include "../yuki.h"

inherit VAULT;


void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("meeting room");
    set_property("light",2);
    set_short("meeting room");
    set_long("%^RESET%^%^ORANGE%^This room is dominated by a large low table "+
	"made of stu%^BLACK%^%^BOLD%^r%^RESET%^%^ORANGE%^dy o%^BLACK%^%^BOLD%^a"+
	"%^RESET%^%^ORANGE%^k. Instead of chairs around it, several %^RESET%^%^BOLD%^"+
	"low cushions%^RESET%^%^ORANGE%^ are arranged around it. The walls are wood "+
	"paneled, and unadorned except for a %^RESET%^large map%^ORANGE%^ on the "+
	"north wall. With the lack of the ever-present feather %^BLACK%^%^BOLD%^in"+
	"signias%^RESET%^%^ORANGE%^ and %^ORANGE%^banners%^ORANGE%^, this room is "+
        "obviously meant to be a neutral room to negotiate and meet.\n%^RESET%^");
    set_exits(([
        "south" : ROOMS"h2",
    ]));  
    set_items(([
        ({"map"}) : "%^RESET%^%^BOLD%^This map is clearly a work of art. Instead of "+
		"showing elevations, political boundaries, or strategic information like "+
		"other maps would, this is an artists representation of the realm. Cities "+
		"are drawn in miniature, and several regions are obscured by drawings of "+
		"fantastical creatures. A giant yeti straddles most of the northern mounta"+
		"ins, a sea serpent lurks to the east of the continent, and giant walking "+
		"trees obscure the forests south of Tharis. While being next to useless as "+
		"a tactical map, the painstaking artistry that went into it makes it a won"+
		"der to behold..%^RESET%^",
        ({"table","oak table"}) : "%^RESET%^%^ORANGE%^This low oak table seems "+
		"very stury.%^RESET%^",
		({"ground", "stone", "stones"}) : "%^RESET%^%^BOLD%^The ground of the "+
		"fortress is set with interlocking stones%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell wood polish.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^The room is almost silent.%^RESET%^");

	set_door("wooden door",ROOMS"h2","south",0);
    set_door_description("wooden door","%^ORANGE%^This heavy oak door looks very sturdy.%^RESET%^");
    set_string("wooden door", "open", "%^ORANGE%^The heavy door opens quietly.%^RESET%^");
    set_string("wooden door", "close", "%^ORANGE%^The heavy door closes without a sound.%^RESET%^");
}
