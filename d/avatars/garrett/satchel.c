#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^Dirty brown sachel%^RESET%^");
	set_id(({ "sachel", "bag", "dirty bag", "dirty sachel" }));
	set_short("%^RESET%^%^ORANGE%^Dirty brown sachel of holding%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Dirty brown sachel%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This seems to be an unremarkable dirty brown sachel to be slung over the shoulder, to carry items inside.%^RESET%^

AVATAR
	);
	set_weight(7);
	set_value(1000);
	set_max_internal_encumbrance(35);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
}


