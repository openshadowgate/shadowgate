#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pendant");
	set_id(({ "necklace", "pendant", "necklace of beauty", "beauty necklace", "beauty pendant" }));
	set_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_obvious_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_long(
@AVATAR
This necklace has a fine %^BOLD%^silver%^RESET%^ chain with a beautiful glimmering %^MAGENTA%^amethyst gem pendant.%^RESET%^ The design is simple yet tasteful.

AVATAR
	);
	set_weight(2);
	set_value(14000);
	set_lore(
@AVATAR
It is rumored that in ancient times an aging yet powerful enchantress magicked the amethyst to give her the illusion of eternal beauty.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" is bathed in beauty as the necklace is slipped on.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel beautiful as you slip on your necklace.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" looks less pretty as the necklace is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel sad as you remove your necklace.%^RESET%^");
	return 1;
}
