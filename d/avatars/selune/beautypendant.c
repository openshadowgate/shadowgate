#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("beautypendant");
	set_id(({ "necklace", "beauty necklace", "necklace of beauty", "pendant" }));
	set_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_obvious_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_long(
@AVATAR
This necklace has a fine %^BOLD%^silver%^RESET%^ chain with a beautiful glimmering %^MAGENTA%^amethyst gem pendant.%^RESET%^  The necklace is of a simple yet tasteful design.

AVATAR
	);
	set_weight(2);
	set_value(14000);
	set_lore(
@AVATAR
It is rumored that an aging enchantress magicked the gem to give her eternal beauty.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" starts to glow with unusual beauty as she slips on the $0.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel the warmth of beauty surround you as you wear this necklace.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" sighs sadly as she removes $0.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You sigh sadly as you remove your necklace.%^RESET%^");
	return 1;
}
