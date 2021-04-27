#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tail");
	set_id(({ "tail" }));
	set_short("dragon tail");
	set_obvious_short("dragon tail");
	set_long(
@AVATAR
dragon tail, duh

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(3,10);
	set_large_wc(3,10);
	set_property("enchantment",3);
}



