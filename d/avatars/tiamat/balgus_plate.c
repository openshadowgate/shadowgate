#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("plate");
	set_id(({ "plate" }));
	set_short("%^BOLD%^%^WHITE%^Plate of Old Kinnesaruda%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Plate of Old Kinnesaruda%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Lucky you, you found some neat armor.  Unfortunately, this is for immortal use only.  Please offer or have an imm pick it up.  Mwuh.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(1);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(10);
}



