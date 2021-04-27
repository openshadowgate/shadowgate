#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("testdagger");
	set_id(({ "dagger", "testdagger" }));
	set_short("Garrett's Test Dagger");
	set_obvious_short("sniny dagger");
	set_long(
@AVATAR
Garrett's well used and stabbity dagger!

AVATAR
	);
	set_weight(1);
	set_value(10000);
	set_lore(
@AVATAR
This dagger deals much death.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(6,2);
	set_large_wc(6,4);
	set_property("enchantment",10);
	set_ac(2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" wields "+query_short()+"",ETO);
	tell_object(ETO,""+query_short()+" grabs the weapon.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" releases "+query_short()+"",ETO);
	tell_object(ETO,"You release "+query_short()+".");
	return 1;
}
