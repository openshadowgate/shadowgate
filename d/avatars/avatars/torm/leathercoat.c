#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("long leather coat");
	set_id(({ "coat", "long coat", "leather coat", "long leather coat" }));
	set_short("%^RESET%^%^RED%^Long Leather Coat%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This coat is made from dark red leather.  It has a high, rounded collar and is not too broad across the shoulders making it unsuitable for anyone not of a slender build.  The coat tapers in from the shoulders towards the waist before flaring out again as it reaches ankle height, affording a good fit whilst not impeding movement.  %^BOLD%^%^BLACK%^The coat has been fully lined with black silk.  The lining of the coat conceals a small pocket.

AVATAR
	);
	set_weight(6);
	set_value(1000);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}


