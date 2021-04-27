#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("aitem");
	set_id(({ "aitem" }));
	set_short("item");
	set_obvious_short("item");
	set_long(
@AVATAR
item

AVATAR
	);
	set_weight(1);
	set_value(0);
}