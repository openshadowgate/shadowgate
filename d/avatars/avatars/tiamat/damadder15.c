#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("band");
	set_id(({ "adder", "band" }));
	set_short("%^RESET%^%^ORANGE%^copper band%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^copper band%^RESET%^");
	set_long(
@AVATAR
This is an object for immortal-use only.  If it should come into your possession, please offer it or have an immortal take it away.  Thank you.

AVATAR
	);
	set("read",
@AVATAR
Damage adder 15

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(1);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	if(userp(ETO) && !avatarp(ETO)) return 0;
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(15);
	return 1;
}

int remove_func(){
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-15);
	return 1;
}

