#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("blue short sleeved shirt");
	set_id(({ "shirt", "blue shirt", "short sleeved shirt", "blue short sleeved shirt" }));
	set_short("%^RESET%^%^BLUE%^A de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e short sleeved shirt%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e short sleeved shirt%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This shirt is made from linen died a %^RESET%^%^BLUE%^de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^.  It has been tailored to fit loosely on the body and not hinder the wearer's movement.  The sleeves have been sewn short and would appear to reach just above the wearers elbows.  The shirt has a short collar that is turned down on the edges, adding a bit of %^BOLD%^%^MAGENTA%^flair %^RESET%^to the garment.  Fancy %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d %^RESET%^laces run along the front of the shirt from the wearer's sternum to the collar.  This somewhat fanciful garment is obviously styled to be worn by a male, as a busty female just wouldn't look proper in such a thing.

AVATAR
	);
	set_weight(5);
	set_value(500);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}


