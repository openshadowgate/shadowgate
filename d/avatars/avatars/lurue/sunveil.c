#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("veil");
	set_id(({ "veil", "sun veil", "suns veil", "sun's veil", "pins", "pin", "hairpins", "hairpin" }));
	set_short("%^BOLD%^%^WHITE%^S%^YELLOW%^u%^MAGENTA%^n%^WHITE%^'s V%^YELLOW%^e%^MAGENTA%^i%^WHITE%^l%^RESET%^");
	set_obvious_short("%^RESET%^a pair of %^BOLD%^%^WHITE%^m%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^or b%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^g%^WHITE%^ht %^RESET%^hairpins");
	set_long(
@AVATAR
%^YELLOW%^Truly an amazing piece of magic, this garment appears to be little more then a pair of hairpins made out of some %^WHITE%^silvery%^YELLOW%^, mirror bright material.  Their simple design allows the wearer to pin back a few locks of hair on each temple, or anywhere within their hair simply, by sliding the locks between the clasp and pinching it downward.  Amazingly, it is when the two pins are secured that the magic of these pins come to %^WHITE%^light%^YELLOW%^.  For as the clasps are set together, bands of pure %^WHITE%^s%^YELLOW%^u%^MAGENTA%^n%^YELLOW%^l%^WHITE%^ig%^YELLOW%^h%^WHITE%^t %^YELLOW%^pour out of them, forming loops of %^WHITE%^sparkling light %^YELLOW%^from one clasp to the other.  Depending on how the pins are worn, this veil of light can be worn across the lower half of the face or over the hair like a snood or scarf.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(6000);
	set_lore(
@AVATAR
On close inspection, you realize that the mirror bright pins are actually made from thin slices of dragon scale.  Though what kind of dragon scale you're not sure.  They look too bright to be silver dragon scales, but perhaps that is what they are.  In any case, they must hold some special form of magic to create the illumination effects that they can produce.  Perhaps even dragon magic, and you find yourself wondering if they hold other traits of dragon magic, such as their ability to resist magical attacks, or perhaps cast a spell of dancing light.  Though, silver dragons don't usually do that and they don't glow with the rays of morning light.. Hmm.

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" wears the two hairpins, beams of %^YELLOW%^s%^WHITE%^u%^MAGENTA%^n%^WHITE%^l%^YELLOW%^ig%^WHITE%^h%^YELLOW%^t %^WHITE%^stretch between them forming a veil of light.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The two hairpins shimmer as beams of %^YELLOW%^s%^WHITE%^u%^MAGENTA%^n%^WHITE%^l%^YELLOW%^ig%^WHITE%^h%^YELLOW%^t %^WHITE%^stretch between them forming a veil of light.%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The veil of light vanishes as "+ETOQCN+" removes the two %^BOLD%^%^WHITE%^m%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^or b%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^g%^WHITE%^ht hairpins.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The veil of light vanishes as you remove the two %^BOLD%^%^WHITE%^m%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^or b%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^g%^WHITE%^ht hairpins.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}

