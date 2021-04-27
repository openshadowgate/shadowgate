#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wand");
	set_id(({ "wand" }));
	set_short("A wand");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
}