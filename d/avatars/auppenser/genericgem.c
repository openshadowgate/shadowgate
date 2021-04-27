#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Generic Gem");
	set_id(({ "gem", "stone", "jewel", "rock" }));
	set_short("A generic gem.");
	set_obvious_short("A generic gem.");
	set_long(
@AVATAR
A generic gem.

AVATAR
	);
	set_weight(3);
	set_value(225);
}