#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^MAGENTA%^A circlet of %^RED%^l%^ORANGE%^e%^GREEN%^av%^ORANGE%^e%^RED%^s%^RESET%^");
	set_id(({ "circlet", "circlet of leaves" }));
	set_short("%^RESET%^%^MAGENTA%^A %^RED%^ci%^ORANGE%^r%^GREEN%^c%^ORANGE%^l%^RED%^et%^MAGENTA%^ of %^RED%^l%^ORANGE%^e%^GREEN%^av%^ORANGE%^e%^RED%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A %^RED%^ci%^ORANGE%^r%^GREEN%^c%^ORANGE%^l%^RED%^et%^MAGENTA%^ of %^RED%^l%^ORANGE%^e%^GREEN%^av%^ORANGE%^e%^RED%^s%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Various %^RED%^co%^MAGENTA%^lor%^RED%^ed%^RESET%^ metals have been delicately shaped into %^GREEN%^l%^RED%^e%^ORANGE%^a%^RED%^f%^GREEN%^y v%^ORANGE%^i%^MAGENTA%^n%^ORANGE%^e%^GREEN%^s%^RESET%^ and twisted together to create this magnificent headpiece. Ranging in shades from %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^t g%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n%^RESET%^ to %^MAGENTA%^d%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^k%^RESET%^ shades of %^MAGENTA%^p%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^le%^RESET%^, the crown seems to represent the beauty found in each %^RESET%^%^ORANGE%^se%^GREEN%^as%^ORANGE%^on%^RESET%^. Although scarce, a few matching %^RED%^g%^MAGENTA%^e%^GREEN%^m%^ORANGE%^s%^RESET%^ have been embedded within the leaves to add a simple s%^BOLD%^p%^RESET%^ar%^BOLD%^k%^RESET%^le when caught in the light.

AVATAR
	);
	set_weight(3);
	set_value(1200);
	set_lore(
@AVATAR
This is one of the many fine pieces of jewelry crafted by the praised designer Chelzy Boyinski. Each piece is unique and highly sought after by collectors of beautiful things.

AVATAR
	);
	set_property("lore difficulty",17);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}


