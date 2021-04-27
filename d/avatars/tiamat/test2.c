#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("test mace");
	set_id(({ "mace", "test mace" }));
	set_short("test mace");
	set_obvious_short("test mace");
	set_long(
@AVATAR
test mace, nub

AVATAR
	);
	set_weight(3);
	set_value(3);
	set_type("bludgeoning");
	set_prof_type("boogie");
	set_size(2);
	set_wc(1,4);
	set_large_wc(1,59);
	set_property("enchantment",2);
}



