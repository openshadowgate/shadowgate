#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("treasure pile");
	set_id(({ "treasure pile", "pile" }));
	set_short("%^YELLOW%^a large pile of treasure%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This large pile of treasure is just that, a pile of glimmering gems, glittering coins and an assortment of strange and wondrous objects.  Who knows what all could be in there if you dug around in it.  Certainly a few things of value will catch your eye.%^RESET%^

AVATAR
	);
	set_weight(200);
	set_value(0);
	set_max_internal_encumbrance(200);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(3);
	set_property("enchantment",0);
}



