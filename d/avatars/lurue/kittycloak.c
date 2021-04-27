#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "cloak", "calico cloak", "kitten's cloak", "kitty cloak", "kitten cloak" }));
	set_short("%^RESET%^%^ORANGE%^kitten's c%^BLACK%^%^BOLD%^o%^RESET%^l%^ORANGE%^o%^RED%^r%^BLACK%^%^BOLD%^f%^RESET%^u%^ORANGE%^l cloak%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^RED%^c%^BOLD%^%^BLACK%^a%^RESET%^l%^ORANGE%^i%^BOLD%^%^BLACK%^c%^RESET%^o %^ORANGE%^colored cloak%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Made from several pieces of dyed leather, this cloak is a mottled garment of %^RED%^red%^ORANGE%^, orange, %^YELLOW%^yellow %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^dark brown%^RESET%^%^ORANGE%^.  Though there is no real order to the pattern, it is a well made garment never the less.  Lined with a thin layer of %^RESET%^fawn %^ORANGE%^colored skilk, the cloak is thick and voluminous, easily wrapping itself around the wearer's body with fabric to spare.  The hood is likewise full, covering the head with room to spare.  Though a great deal of fabric, it is surprisingly light and comfortable.  A small clasp, fashioned from %^RESET%^silver wire%^ORANGE%^ and an oval piece of %^GREEN%^peridot%^ORANGE%^, create the closure for this comfortable garment.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(500);
	set_lore(
@AVATAR
Keesha Leoten, also known by her nickname Kitten, was a young woman with a talent for working with gems and metals.  Though she was not very well known as a person, due to her shyness, her work has been seen by many.  The tiny characters made of gold, platinum, bronze and copper were studded with small bits of gem and stylized into decorative jewelry that was often well received by those of high station.  Because of her incredible shyness, Kitten usually wore a heavy cloak that encompassed her full frame.  Made, like most of her work, from scraps of leather, the garment was well known, even if the woman wearing it was not.

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^The thick folds of the garment wrap about you, protecting you from many things.%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^As finicky as a kitten, the protection slides away.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}

