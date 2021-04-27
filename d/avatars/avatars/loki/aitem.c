#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("item");
	set_id(({ "item" }));
	set_short("An item");
	set_obvious_short("an Item");
	set_long(
@AVATAR
An item

AVATAR
	);
	set_weight(2);
	set_value(0);
}
