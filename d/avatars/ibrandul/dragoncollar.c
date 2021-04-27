#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^black collar%^RESET%^");
	set_id(({ "collar" }));
	set_short("%^BLACK%^%^BOLD%^black collar%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black collar%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(3);
	set_property("enchantment",4);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(4);
	ETO->add_damage_bonus(4);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-4);
	ETO->add_damage_bonus(-4);
	return 1;
}
