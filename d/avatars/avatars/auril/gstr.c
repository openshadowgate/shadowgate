#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("stre");
	set_id(({ "armor" }));
	set_short("Soft armor");
	set_obvious_short("Soft armor");
	set_long(
@AVATAR
This is soft, old, rotten armor.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",0);
	set_ac(14);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You wear it");
	ETO->add_attack_bonus(15);
	ETO->set_property("magic resistance",100);
	ETO->add_damage_bonus(5);
	ETO->add_stat_bonus("strength",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You sadly remove it");
	ETO->add_attack_bonus(-15);
	ETO->set_property("magic resistance",-100);
	ETO->add_damage_bonus(-5);
	ETO->add_stat_bonus("strength",-5);
	return 1;
}
