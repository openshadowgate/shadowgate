#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("clasp");
	set_id(({ "clasp", "cloth clasp" }));
	set_short("%^RESET%^%^BOLD%^a silver cloak clasp%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^a silver cloak clasp%^RESET%^");
	set_long(
@AVATAR
A silver cloth clasp fashioned into the image of a triangle. Within the triangle three interlocking rings made from platinum, electrum and copper are attached. The clasp features a long silver pin that slips into the cloak and a locking device for keeping it in place.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}


