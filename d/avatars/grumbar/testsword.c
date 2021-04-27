#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("testsword");
	set_id(({ "test sword" }));
	set_short("it's a testy sword");
	set_obvious_short("testy sword");
	set_long(
@AVATAR
test test test

AVATAR
	);
	set_weight(6);
	set_value(1000);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(1);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",8);
}


