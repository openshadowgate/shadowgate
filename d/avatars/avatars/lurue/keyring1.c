#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("keyring");
	set_id(({ "keyring", "keyring1", "kr1", "white keyring" }));
	set_short("%^BOLD%^%^WHITE%^a metal keyring%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a metal keyring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This keyring is made of some type of white metal that has been bent into a large circle that overlaps itself, trapping all the keys upon it while still allowing them to be removed and added as needed.  A strip of white leather has been attached to the metal ring, making it easy to attach the ring to ones belt.%^RESET%^

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


