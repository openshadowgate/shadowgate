#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("nfsword");
	set_id(({ "sword", "longsword", "long sword", "nightfall sword" }));
	set_short("Nightfall's Sword");
	set_obvious_short("Nightfall's Sword");
	set_long(
@AVATAR
%^BOLD%^This long sword is approximately 45" in total length from the pommel to the point.  The double-edged blade is 34" long and is extremely sharp. It has been crafted from the finest %^BOLD%^%^BLACK%^platinum%^RESET%^%^BOLD%^ that has been %^BOLD%^%^BLACK%^darkened%^RESET%^%^BOLD%^ through some forging process to a %^BOLD%^%^BLACK%^smokey%^RESET%^%^BOLD%^ tint. %^RESET%^%^BOLD%^  The blade is also tapered and has a %^RED%^blood groove%^RESET%^%^BOLD%^ running nearly its entire length on both sides.  The guard is made of the same %^BOLD%^%^BLACK%^darkened platinum%^RESET%^%^BOLD%^ making the blade and guard appear seamless.  Encrusted into the hilt are fine %^BOLD%^%^RED%^rubies%^RESET%^%^BOLD%^ %^GREEN%^emeralds%^RESET%^%^BOLD%^ and %^BOLD%^%^BLUE%^sapphires%^RESET%^%^BOLD%^ that all seem to shine with an inner fire. The grip itself is wood wrapped in %^BOLD%^%^BLACK%^black leather.%^RESET%^%^BOLD%^ The pommel is large allowing for better balance and is made of polished %^BOLD%^%^BLACK%^onyx.%^RESET%^

AVATAR
	);
	set_weight(7);
	set_value(550);
	set_lore(
@AVATAR
This sword was made by Ianthe Nul-Vekkar Serutan for Nightfall, The Blade of Shar.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,4);
	set_large_wc(3,6);
	set_property("enchantment",3);
}


