#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^YELLOW%^A golden chain%^RESET%^");
	set_id(({ "chain", "Chain" }));
	set_short("%^BOLD%^%^YELLOW%^A golden chain%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^A golden chain%^RESET%^");
	set_long(
@AVATAR
This is a golden chain, its about two feet long.

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "left leg" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}


