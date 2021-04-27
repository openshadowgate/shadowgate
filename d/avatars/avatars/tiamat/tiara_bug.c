#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Tiara of Vicissitude");
	set_id(({ "tiara", "crown" }));
	set_short("%^RESET%^%^MAGENTA%^T%^BOLD%^i%^RESET%^%^CYAN%^a%^MAGENTA%^ra of V%^BOLD%^i%^RESET%^%^MAGENTA%^cis%^CYAN%^s%^MAGENTA%^i%^CYAN%^t%^MAGENTA%^u%^BOLD%^d%^RESET%^%^MAGENTA%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^tiara made of s%^BOLD%^h%^CYAN%^e%^RESET%^%^MAGENTA%^ll%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This is a thin piece of headwear of unusual design and craftsmanship.  The band meant to be worn around the head is semi-circular and would fit just above the ears.  It appears to be made of a dense %^BOLD%^shell-like substance%^RESET%^%^MAGENTA%^.  Five spines grow upward from the band like a menacing crown and have the %^CYAN%^ir%^BOLD%^ide%^MAGENTA%^sce%^RESET%^%^MAGENTA%^nt shine of insect carapace.  The first, center spine covers the forehead and contains a strange %^CYAN%^gemstone%^MAGENTA%^ that resembles a compound eye.  The other spines grow upward in even intervals away from the center and curve inward, securing the tiara to the head.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1100);
	set("intbonus",2);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^The eye in "+ETOQCN+"'s tiara looks around for a moment as they wear it.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^You feel your head swim among the stars briefly.%^RESET%^");
	ETO->set_property("magic resistance",4);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^The eye in "+ETOQCN+"'s tiara blinks as they remove it.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^Your mind slows down now free of the strange tiara.%^RESET%^");
	ETO->set_property("magic resistance",-4);
	return 1;
}
