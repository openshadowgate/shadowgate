#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an item");
	set_id(({ "aitem" }));
	set_short("an item");
	set_obvious_short("an item");
	set_long(
@AVATAR
an item

AVATAR
	);
	set_weight(1);
	set_value(0);
}
