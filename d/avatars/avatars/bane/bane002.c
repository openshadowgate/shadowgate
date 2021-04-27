#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Holder of nifty things");
	set_id(({ "robe", "Robe" }));
	set_short("%^RESET%^%^BLUE%^Holder of nifty things%^RESET%^");
	set_obvious_short("robe");
	set_long(
@AVATAR
This robe is a holder of nifty things.

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
Said ot hold things, nifty things, things of a god or the like.

AVATAR
	);
	set_property("lore difficulty",0);
	set_max_internal_encumbrance(10000000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",30);
	set_ac(10000);
}


