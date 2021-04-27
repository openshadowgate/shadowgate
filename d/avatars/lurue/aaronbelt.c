#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("belt");
	set_id(({ "belt" }));
	set_short("%^BLUE%^a cloth belt%^RESET%^");
	set_obvious_short("%^BLUE%^a cloth belt%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^a cloth belt%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set("dexbonus",1);
	set("dexbonus",2);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(3);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-3);
	return 1;
}
