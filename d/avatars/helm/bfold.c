#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("blindfold");
	set_id(({ "blindfold", "fold", "blind" }));
	set_short("%^BOLD%^%^BLACK%^A soft black blindfold%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A soft black blindfold%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a soft velvet blindfold worn over your eyes to shield them.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" %^BOLD%^%^BLACK%^adjusts his blindfold carefully.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You place the blindfold over your eyes and tie it up behind your head.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" %^BOLD%^%^BLACK%^removes his blindfold.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove your blindfold.%^RESET%^");
	return 1;
}
