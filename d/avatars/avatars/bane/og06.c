#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^A gold chain%^RESET%^");
	set_id(({ "chain", "Chain" }));
	set_short("%^RESET%^%^ORANGE%^A gold chain%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A gold chain%^RESET%^");
	set_long(
@AVATAR
This is a standard gold chain that is a about one and a half feet long.

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "left arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}


