#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("greaves");
	set_id(({ "greaves" }));
	set_short("%^RESET%^Some greaves%^RESET%^");
	set_obvious_short("%^RESET%^Some greaves%^RESET%^");
	set_long(
@AVATAR
A test.

AVATAR
	);
	set_weight(10);
	set_value(100);
	set_type("armor");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}


