#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^YELLOW%^A gold chain%^RESET%^");
	set_id(({ "chain", "Chain" }));
	set_short("%^BOLD%^%^YELLOW%^A gold chain%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^A gold chain%^RESET%^");
	set_long(
@AVATAR
This is a standard gold chain that is a about two feet long.

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}


