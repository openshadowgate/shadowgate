#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an item");
	set_id(({ "myitem", "item" }));
	set_short("this is an item");
	set_obvious_short("an item");
	set_long(
@AVATAR
Look its an item, use alterobj to change it to something cooler.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
this is lore, yay lore

AVATAR
	);
	set_property("lore difficulty",10);
}
