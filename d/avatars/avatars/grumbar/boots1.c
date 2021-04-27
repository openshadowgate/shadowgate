#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Invisible Boots");
	set_id(({ "boots" }));
	set_short("%^RESET%^%^BLACK%^Invisible Boots%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible boots%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(5);
	set_value(500000);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("dexterity",2);
	ETO->set_property("magic resistance",50);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("dexterity",-2);
	ETO->set_property("magic resistance",-50);
	return 1;
}
