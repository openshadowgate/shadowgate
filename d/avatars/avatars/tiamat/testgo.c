#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tester");
	set_id(({ "sword", "test sword", "tester" }));
	set_short("tester sword");
	set_obvious_short("tester sword");
	set_long(
@AVATAR
this is test, only a test

AVATAR
	);
	set_weight(5);
	set_value(3);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",2);
}



