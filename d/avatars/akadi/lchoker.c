#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^A metal choker%^RESET%^");
	set_id(({ "choker", "necklace" }));
	set_short("%^BOLD%^%^BLACK%^Spiked M%^RESET%^e%^BOLD%^t%^RESET%^a%^BOLD%^%^BLACK%^l Ch%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ker%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^spiked %^BOLD%^%^BLACK%^metal %^BOLD%^%^WHITE%^choker%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This choker is crafted from highly reflective obsidian. It fits perfectly around the wearer's neck and has been decorated with small %^RESET%^silver %^BOLD%^%^BLACK%^barbs.%^RESET%^


AVATAR
	);
	set_weight(5);
	set_value(300);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(2);
}


