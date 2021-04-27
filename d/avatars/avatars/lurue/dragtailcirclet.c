#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet", "dragontail circlet", "dragontail" }));
	set_short("%^YELLOW%^d%^WHITE%^r%^CYAN%^a%^YELLOW%^go%^RESET%^%^ORANGE%^n%^YELLOW%^t%^WHITE%^a%^CYAN%^i%^YELLOW%^l c%^CYAN%^i%^YELLOW%^r%^WHITE%^c%^RESET%^%^ORANGE%^l%^BOLD%^%^CYAN%^e%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^YELLOW%^a %^RESET%^%^ORANGE%^gold %^YELLOW%^and %^RESET%^mithril %^YELLOW%^circlet%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^A thin metal band of pounded %^RESET%^mithril %^YELLOW%^and %^RESET%^%^ORANGE%^gold %^YELLOW%^has been twisted and wrapped about itself to form this unique circlet.  Designed to look like a %^RESET%^%^ORANGE%^golden dragon %^YELLOW%^chasing its tail, the tail curls through the dragon's mouth and hangs down over the brow, dripping a %^CYAN%^light blue amethyst %^YELLOW%^from its tip.  This gem is repeated in small flecks for the %^CYAN%^eyes %^YELLOW%^as well as along the top edge to highlight each of the raised back ridges.  Clawed feet extend down to either side of the ear, stylized they bend about the ears keeping the head peace securely set on the head.  Though the dragon is winged, the wings are folded tight to the body and are difficult to see amongst the %^RESET%^%^ORANGE%^scaled %^YELLOW%^metal.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1000);
	set_lore(
@AVATAR
Throughout the years, jewelers have made items that resemble animals, amongst them the dragon is an often seen.  Wings raised or folded, mouth snarling and teeth bared or a gentle expression filled with wisdom, whatever the design called for, the dragon jewelry has always been a popular seller.  This piece, like many before it, was designed as a fanciful bit of jewelry which was later enchanted with a bit of protective magic to make it both lovely to wear and practical. 

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
}



