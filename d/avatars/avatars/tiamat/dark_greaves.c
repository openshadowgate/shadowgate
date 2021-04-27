#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dark greaves");
	set_id(({ "greaves" }));
	set_short("%^BOLD%^%^BLACK%^dark iron greaves%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^dark iron greaves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a set of greaves, designed from dark iron, heavy in carbon and strong beyond the skill of most artisans.  The greaves are designed from closely interlocking metal plates, fitting close to protect the lower legs.  They are heavily oiled and still smell like smoke from the forge from which they were wrought.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1000);
	set_type("armor");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}


