#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("crimsonrobe");
	set_id(({ "robe", " priest's robe", "crimson robe" }));
	set_short("%^BOLD%^%^RED%^Crimson Robe%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Crimson Robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a long flowing robe with an over sized hood of a deep crimson color.  The wearer merely slides the robe over his head in order to wear it. It's made of wool and looks quite comfortable as it fits loosely on the body. The robe falls to the ankle and the hood conceals most of the face falling past the brow.  Its sleeves are long and loose, concealing the hands.  The robe is unadorned and is rather plain, its simple beauty derived merely from its rich color.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_max_internal_encumbrance(10);
	set_type("chain");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
}


