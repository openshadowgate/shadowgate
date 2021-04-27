#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rod");
	set_id(({ "rod" }));
	set_short("A rod.");
	set_long(
@AVATAR
A rod

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}