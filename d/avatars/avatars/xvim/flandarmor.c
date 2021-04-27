#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Fine gnomish leather");
	set_id(({ "armor" }));
	set_short("fine gnomish leather");
	set_obvious_short("leather armor");
	set_long(
@AVATAR
This is fine gnomish handywork

AVATAR
	);
	set_weight(10);
	set_value(400);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",2);
	set_ac(4);
}


