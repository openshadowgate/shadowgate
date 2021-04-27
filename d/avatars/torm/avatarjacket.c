#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Torm's Jacket");
	set_id(({ "jacket", "torm's jacket", "torms jacket" }));
	set_short("%^BOLD%^%^BLUE%^Velvet Jacket of Torm%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^Blue Velvet Jacket%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is a perfectly tailored jacket that fits the wearer exquisetley.  The cut of the jacket shows off his amazingly muscular physique.  Helpfully the tailor has incorporated a pocket to store all those useful odds and ends.  %^BOLD%^%^BLACKThere is a label inside the jacket with some small embroidered lettering that you can read.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^If you have this jacket and are NOT an IMMORTAL return it to one immediately or OFFER IT.  Thankyou.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(20);
	set_value(2);
	set_lore(
@AVATAR
This is Torm's Jacket.

AVATAR
	);
	set_max_internal_encumbrance(1500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(200);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" looks stunning in that snug fitting jacket%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^ The jacket fits you perfectly%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}

