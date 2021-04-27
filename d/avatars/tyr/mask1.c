#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("A Mask");
	set_id(({ "mask" }));
	set_short("%^BLUE%^Dark %^ORANGE%^Mask%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^a Mask%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This face covering is suspected of belonging to servants of Mask.  It represents a "mark" of acknowedged faithfulness to the great Trickster%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(450);
set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
set_ac(0);
}


