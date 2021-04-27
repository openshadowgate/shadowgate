#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an item");
	set_id(({ "aitem" }));
	set_short("aitem");
	set_obvious_short("aitem");
	set_long(
@AVATAR
This is an item of some sort. It could probably take almost any shape.

AVATAR
	);
	set_weight(1);
	set_value(0);
}