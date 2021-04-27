#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create(){
	::create();
	set_name("testobj");
	set_id(({ "rapier", "test rapier" }));
	set_short("Super Test Rapier");
	set_obvious_short("a black rapier");
	set_long("A SUPER RAPIER
");
	set_value(100);
	set_property("enchantment",10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" wields $POSS "+query_short()+" and flips the fuck out!",ETO);
	tell_object(ETO,"You wield your "+query_short()+" and flip the fuck out!");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}

