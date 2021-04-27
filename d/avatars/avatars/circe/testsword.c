#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
	::create();
	set_name("test sword");
	add_id(({ "you better work", "dammit" }));
	set_short("Long Sword");
	set_obvious_short("long sword");
	set_long(
@AVATAR
This is a long sword.

AVATAR
	);
	set_value(150);
	set_property("enchantment",4);
	set_ac(0);
}


