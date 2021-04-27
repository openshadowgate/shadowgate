#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Invisible Cloak");
	set_id(({ "cloak" }));
	set_short("%^RESET%^%^BLACK%^Invisible Cloak%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible cloak%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(7);
	set_value(750000);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",20);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",5);
	ETO->set_property("magic resistance",50);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",-5);
	ETO->set_property("magic resistance",-50);
	return 1;
}
