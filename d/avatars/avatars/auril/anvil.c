#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("anvil");
	set_id(({ "anvil" }));
	set_short("A small anvil");
	set_obvious_short("A small anvil");
	set_long(
@AVATAR
This is a small, heavy anvil.

AVATAR
	);
	set_weight(30);
	set_value(0);
	set_property("lore difficulty",3);
}