#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather belt");
	set_id(({ "belt", " leather belt" }));
	set_short("%^RESET%^ORANGE%^Leather Belt%^RESET%^");
	set_obvious_short("Belt");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^This is a simple leather belt with a platinum buckle.  It appears to be of appropriate size and length for a human sized creature.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(20);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",0);
}


