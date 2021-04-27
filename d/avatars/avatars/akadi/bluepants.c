#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^BLUE%^Blue s%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^d%^RESET%^%^BLUE%^e pants%^RESET%^");
	set_id(({ "pants", "breeches", "leggings" }));
	set_short("%^RESET%^%^BLUE%^Blue s%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^d%^RESET%^%^BLUE%^e pants%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^Blue s%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^d%^RESET%^%^BLUE%^e pants%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^These large pants are made from soft suede dyed a %^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^ar%^RESET%^%^BLUE%^k%^BOLD%^%^BLUE%^ shade of %^RESET%^%^BLUE%^blue%^BOLD%^%^BLUE%^. Thick but supple, the s%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^e has been fashioned in such a way that it looks and feels as if it will provide ample protection to the wearer while not hindering movement. Faint white %^RESET%^pi%^BLUE%^ns%^RESET%^tr%^BLUE%^ip%^RESET%^es%^BOLD%^%^BLUE%^ add some flair, as do the %^BOLD%^%^CYAN%^sa%^RESET%^%^CYAN%^p%^RESET%^%^BLUE%^ph%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^re%^BOLD%^%^BLUE%^ clasps adorning the front panel, used to keep the pants securely closed.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1500);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(3);
	set_property("enchantment",1);
}


