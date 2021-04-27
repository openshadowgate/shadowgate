#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("miss");
	set_id(({ "weapon" }));
	set_short("weapon");
	set_obvious_short("weapon");
	set_long(
@AVATAR
weapon

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
weapon

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("blade");
	set_size(2);
	set_wc(1,1);
	set_large_wc(1,1);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"n");
	ETO->add_attack_bonus(-5000);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(5000);
	return 1;
}
