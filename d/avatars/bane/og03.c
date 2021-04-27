#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^YELLOW%^A gold medallion%^RESET%^");
	set_id(({ "chain", "Chain", "medallion", "Medallion" }));
	set_short("%^BOLD%^%^YELLOW%^A gold medallion%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^A gold medallion%^RESET%^");
	set_long(
@AVATAR
This is a thick gold chain with a large gold medallion hanging from it.

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}


