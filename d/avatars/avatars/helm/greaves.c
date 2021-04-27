#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather greaves");
	set_id(({ "leather", "greaves", "leather greaves" }));
	set_short("%^RESET%^%^ORANGE%^leather greaves%^RESET%^");
	set_obvious_short("leather greaves");
	set_long(
@AVATAR
Greaves are for the legs what bracers are for the arms. These greaves are made of several layers of hard leather and are worn on the legs to protect the wearers shins and knees from damage.

AVATAR
	);
	set_weight(4);
	set_value(0);
	set_type("armor");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(2);
}


