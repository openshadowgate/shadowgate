#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Invisible Ring");
	set_id(({ "invisible ring" }));
	set_short("%^RESET%^%^BLACK%^Invisible Ring%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible ring%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(2);
	set_value(500000);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",20);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("constitution",5);
	ETO->set_property("magic resistance",50);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("constitution",-5);
	ETO->set_property("magic resistance",-50);
	return 1;
}
