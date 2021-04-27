#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("tattoo");
	set_id(({ "tattoo" }));
	set_short("%^BOLD%^%^BLACK%^a tattoo of a black hand%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a tattoo of a black hand%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This appears to be a tattoo of a black hand.  Judging by the way the hand is shaped it is of a woman's hand.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",-1);
	set_ac(1);
}


