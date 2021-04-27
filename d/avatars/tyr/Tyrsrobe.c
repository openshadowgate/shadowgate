#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Stabity%^GREEN%^ Proof%^WHITE%^Robe%^RESET%^");
	set_id(({ "robe", " robes" }));
	set_short("%^RED%^Tyr's Robe%^RESET%^");
	set_obvious_short("%^RED%^Tyr's Robe%^RESET%^");
	set_long(
@AVATAR
%^RED%^Tyr's Robe%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(1000000);
	set_max_internal_encumbrance(100000);
	set_type("clothing");
	set_limbs(({ "left arm", "right arm" }));
	set_size(2);
	set_property("enchantment",15);
	set_ac(20);
}


