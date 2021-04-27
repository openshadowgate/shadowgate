#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bodies");
	set_id(({ "bodies" }));
	set_short("A few burt villager bodies are here");
	set_obvious_short("A few burt villager bodies are here");
	set_long(
@AVATAR
These bodies look to have burned by some sort of massive fire. The ground is scorched near them.

AVATAR
	);
	set_weight(500);
	set_value(0);
	set_property("lore difficulty",5);
}