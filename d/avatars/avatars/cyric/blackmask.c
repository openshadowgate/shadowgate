#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("black mask");
	set_id(({ "mask", "black mask", "silk mask", "holy symbol", "symbol", "black silk mask" }));
	set_short("%^BOLD%^%^BLACK%^Silk Mask%^RESET%^");
	set_obvious_short("black mask");
	set_long(
@AVATAR
This is a silk mask as black as pitch.  It functions to hide the wearer's identity, covering all features from the nose up except for two narrow slits for eyes.  A silk mask is also the symbol of Mask, the lord of shadows.

AVATAR
	);
	set_weight(0);
	set_value(5);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}


