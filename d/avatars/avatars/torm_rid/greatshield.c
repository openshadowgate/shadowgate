#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Great Shield");
	set_id(({ "shield" }));
	set_short("%^BOLD%^%^BLUE%^Holy Great Shield");
	set_obvious_short("%^WHITE%^Giant silver shield");
	set_long(
@AVATAR
%^WHITE%^Made of silver, this shield is massive. Protecting his right arm, torso and upper part of his right leg. The emblem of a %^BOLD%^%^WHITE%^glowing%^RESET%^%^WHITE%^ shield in the middle of it. A deep %^BLUE%^blue %^WHITE%^aura surrounds it, making its protection even greater.

AVATAR
	);
	set_weight(50);
	set_value(0);
	set_type("armor");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(20);
}


