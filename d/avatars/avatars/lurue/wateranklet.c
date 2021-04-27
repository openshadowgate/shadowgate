#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("tattoo");
	set_id(({ "tattoo", "water tattoo" }));
	set_short("%^RESET%^%^CYAN%^a small %^BLUE%^w%^WHITE%^a%^CYAN%^t%^BOLD%^e%^BLUE%^r%^RESET%^%^BLUE%^y%^CYAN%^ tattoo%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a small %^BLUE%^w%^WHITE%^a%^CYAN%^t%^BOLD%^e%^BLUE%^r%^RESET%^%^BLUE%^y%^CYAN%^ tattoo%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This small %^BLUE%^w%^WHITE%^a%^CYAN%^t%^BOLD%^e%^BLUE%^r%^RESET%^%^BLUE%^y%^CYAN%^ tattoo rings the back side of the ankle of the wearer.  It flows along a smooth and old looking scar with several %^BLUE%^d%^RESET%^r%^CYAN%^o%^BOLD%^p%^BLUE%^l%^RESET%^%^e%^CYAN%^t%^BLUE%^s%^CYAN%^ of water dripping downward.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
This tattoo appeared upon the wearer's ankle after she was healed by a half-orc priest of Istishia.

AVATAR
	);
	set_property("lore difficulty",15);
        set_type("ring");
	set_limbs(({ "left leg" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
}


