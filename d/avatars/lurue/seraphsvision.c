#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "seraphs vision", "seraph's vision", "vision", "circlet" }));
	set_short("%^YELLOW%^S%^WHITE%^e%^CYAN%^r%^YELLOW%^ap%^WHITE%^h%^YELLOW%^'s V%^WHITE%^i%^CYAN%^s%^YELLOW%^is%^CYAN%^o%^YELLOW%^n%^RESET%^");
	set_obvious_short("%^YELLOW%^a %^RESET%^%^ORANGE%^gold %^YELLOW%^and %^RESET%^mithril %^YELLOW%^circlet%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^A thin metal band of pounded %^RESET%^mithril %^YELLOW%^and %^RESET%^%^ORANGE%^gold %^YELLOW%^has been twisted and wrapped about itself to form this unique circlet.  Designed to look like a %^RESET%^%^ORANGE%^feathered dragon %^YELLOW%^chasing its tail, the tail curls through the dragon's mouth and hangs down over the brow, dripping a %^CYAN%^light blue amethyst %^YELLOW%^from its tip.  This gem is repeated in small flecks for the %^CYAN%^eyes %^YELLOW%^as well as along the top edge to highlight each of the raised back ridges.  Clawed feet extend down to either side of the ear, stylized they bend about the ears keeping the head peace securely set on the head.  Though the dragon is winged, the wings are folded tight to the body and are difficult to see amongst the %^RESET%^%^ORANGE%^scaled %^YELLOW%^metal.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(5000);
	set_lore(
@AVATAR
Throughout the years, jewelers have made items that resemble animals, amongst them the dragon is an often seen.  Wings raised or folded, mouth snarling and teeth bared or a gentle expression filled with wisdom, whatever the design called for, the dragon jewelry has always been a popular seller.  This piece, like many before it, was designed as a fanciful bit of jewelry which was later enchanted with a bit of protective magic to make it both lovely to wear and practical.   This piece is different though, and on close inspection it would seem to be elven in make, a piece that is incredibly old and glitters with power.

AVATAR
	);
	set_property("lore difficulty",15);
	set("intbonus",1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^WHITE%^The %^CYAN%^gem%^WHITE%^ upon the dragon's tail %^CYAN%^glitters%^WHITE%^ for a moment.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^WHITE%^The %^CYAN%^gem%^WHITE%^ upon the dragon's tail %^CYAN%^glitters%^WHITE%^ for a moment.%^RESET%^");
	return 1;
}

