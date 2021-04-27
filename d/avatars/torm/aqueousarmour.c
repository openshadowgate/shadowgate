#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Aqueous Armour");
	set_id(({ "liquid armour", "armour", "aqueous armour" }));
	set_short("%^RESET%^%^BLUE%^Aque%^BOLD%^%^WHITE%^ou%^RESET%^%^BLUE%^s Arm%^BOLD%^%^WHITE%^ou%^RESET%^%^BLUE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^Aqueous Armour%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^As you look at the armour you can see a ripple spread out across the surface.  Whilst it appears to be made mostly of water you are unable to see through it.  As the armour moves around the wearer small crest%^BOLD%^%^WHITE%^in%^RESET%^%^BLUE%^g wa%^BOLD%^%^WHITE%^ve%^RESET%^%^BLUE%^s appear every now and then, and yet it feels solid to the touch.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_lore(
@AVATAR
%^BLUE%^There are few records surviving that detail the history of this armour, and what remains is as likely to be rumour and myth than fact.  The most commonly accepted account is that a small coastal temple of Istishia whose reputation for execellent ceramics had spread far and wide were asked to create a whole selection of fine pots, jars, plates and bowls.  The work that they did was exquisite, and part of the donation made to the temple in thanks was a suit of armour once worn by a water nymph.%^RESET%^

AVATAR
	);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BLUE%^A %^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^p%^RESET%^%^BLUE%^p%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^e spreads out across the armour as you put it on.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BLUE%^The armour pools together on the floor once you remove it.%^RESET%^");
	return 1;
}
