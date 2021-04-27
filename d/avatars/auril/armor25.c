#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor");
	set_id(({ "armor" }));
	set_short("armor");
	set_obvious_short("armor");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(31);
}


