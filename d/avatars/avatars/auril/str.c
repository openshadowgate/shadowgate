#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("str");
	set_id(({ "claw" }));
	set_short("claw");
	set_obvious_short("claw");
	set_long(
@AVATAR
claw

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("claw");
	set_size(1);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",0);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"here",ETO);
	tell_object(ETO,"here");
	ETO->add_stat_bonus("strength",10);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"here",ETO);
	tell_object(ETO,"here");
	ETO->add_stat_bonus("strength",-10);
	return 1;
}
