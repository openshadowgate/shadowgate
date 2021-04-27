#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("watch");
	set_id(({ "cloak" }));
	set_short("%^BOLD%^%^BLACK%^Shadow's Embrace%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A flowing black cloak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This long black cloak looks to be made out of a soft material like silk or satin. It is completely black, no light reflecting from it in the least bit. There is a small %^BOLD%^%^WHITE%^pearl %^BOLD%^%^BLACK%^clasp that holds the cloak together in the front.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(5000);
	set_lore(
@AVATAR
This lets the Mask priests watch you.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",6);
	set_ac(-3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The shadows around "+ETOQCN+" quickly move towards "+ETOQCN+". They wrap themselves around "+ETOQCN+" as the cloak is worn.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You clasp the %^BOLD%^%^WHITE%^pearl %^BOLD%^%^BLACK%^clasp and the cloak wraps itself to fit you perfectly.");
	ETO->add_stat_bonus("wisdom",-2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the cloak and the shadows dissipate from around "+ETOQCN+".",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the cloak and the shadows dissipate from around you.");
     ETO->add_stat_bonus("wisdom",2);
	return 1;
}
