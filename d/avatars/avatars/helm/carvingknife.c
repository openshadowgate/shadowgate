#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Carving knife");
	set_id(({ "knife", "carving knife" }));
	set_short("Carving knife");
	set_long(
@AVATAR
This is a straight and very sharp knife used at home or in the wildlife by the professional skinners.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(0);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,2);
	set_large_wc(1,2);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"As you draw the "+query_short()+" your eyes light up slightly.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"He unwields it",ETO);
	tell_object(ETO,"You unwield it.");
	return 1;
}
