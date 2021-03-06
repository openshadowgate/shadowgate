#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("keyring");
	set_id(({ "keyring", "keyring3", "kr3", "blue keyring" }));
	set_short("%^BOLD%^%^BLUE%^a metal keyring%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a metal keyring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This keyring is made of some type of blue metal that has been bent into a large circle that overlaps itself, trapping all the keys upon it while still allowing them to be removed and added as needed.  A strip of blue leather has been attached to the metal ring, making it easy to attach the ring to ones belt.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_max_internal_encumbrance(1);
	set_type("ring");
	set_limbs(({ "waist" }));
	set_size(1);
	set_property("enchantment",0);
}


