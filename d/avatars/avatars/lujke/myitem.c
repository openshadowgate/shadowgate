#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("myitemname");
	set_id(({ "item" }));
	set_short("an item");
	set_obvious_short("an item");
	set_long(
@AVATAR
This is an item

AVATAR
	);
	set_weight(10);
	set_value(100);
}
