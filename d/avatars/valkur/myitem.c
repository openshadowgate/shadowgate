#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an tem");
	set_id(({ "myitem", "item" }));
	set_short("this is an item");
	set_obvious_short("an item");
	set_long(
@AVATAR
Shucks this is a cool item, use alterobj to something cooler

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This is the most powerful hunk of nuthin in the game wheeeee!

AVATAR
	);
	set_property("lore difficulty",15);
}
