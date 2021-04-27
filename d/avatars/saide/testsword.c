#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("testsword");
	set_id(({ "sword", " test", " test sword" }));
	set_short("test sword");
	set_obvious_short("test sword");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(10);
	set_value(200);
	set_heart_beat(1);
	set_type("slashing");
	set_prof_type("blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",3);
}


