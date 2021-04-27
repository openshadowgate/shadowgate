#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("band");
	set_id(({ "adder", "band" }));
	set_short("%^YELLOW%^gold band%^RESET%^");
	set_obvious_short("%^YELLOW%^gold band%^RESET%^");
	set_long(
@AVATAR
This is an imm-only item.  If you should find one, please offer it or ask an imm to take it away.  Thank you.

AVATAR
	);
	set("read",
@AVATAR
dam adder 45

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
	ETO->add_attack_bonus(10);
	ETO->add_damage_bonus(45);
	return 1;
}

int remove_func(){
	ETO->add_attack_bonus(-10);
	ETO->add_damage_bonus(-45);
	return 1;
}

