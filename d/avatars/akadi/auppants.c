#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Auppenser's Pants of Doom");
	set_id(({ "pants", "leggings" }));
	set_short("%^RESET%^%^CYAN%^Aupp%^BOLD%^e%^RESET%^%^CYAN%^nser's Pa%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^ts of %^BOLD%^%^BLACK%^Doom%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A pair of bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e pants%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Finely crafted from a soft cl%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^th, these pants would make a fine compliment to any man's wardrobe. Although they are l%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^ose-fitting, they are not so baggy as to appear %^RESET%^%^BLUE%^ghetto%^BOLD%^%^BLUE%^. They seem to %^BOLD%^%^BLACK%^radiate%^BLUE%^ a sense of raw %^WHITE%^power%^BLUE%^ and you can't help but wonder if it's the pants or what lies beneath.
%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^To Auppenser from Akadi. Keep that ass covered, would ya?!%^RESET%^

AVATAR
	);
	set_property("lore difficulty",2);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" giggles like a little girl as he wears his "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You can't help but smile as you put on these finely crafted pants.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETOQCN+" gives a sly grin as he removes his "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You carefully remove the nice pants.%^RESET%^");
	ETO->add_attack_bonus(-2);
	return 1;
}
