#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("beautynecklace");
	set_id(({ "necklace", "beauty necklace", "necklace of beauty" }));
	set_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_obvious_short("%^MAGENTA%^Necklace of Beauty%^RESET%^");
	set_long(
@AVATAR
This necklace has a fine %^BOLD%^silver%^RESET%^ chain with a beautiful shimmering %^MAGENTA%^amethyst gem pendant.%^%^RESET%^  It's design is simple but very tasteful.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(14000);
	set_lore(
@AVATAR
It is rumored that an aging enchantress magicked the gem to give her the image of eternal youth.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(-2);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"**",ETO);
	tell_object(ETO,"%^MAGENTA%^Slips the necklace on and is bathed in beauty%^RESET%^");
	return 1;
}

