#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("generic");
	set_id(({ "generic", "thing" }));
	set_short("This is a thing.");
	set_obvious_short("This is a thing.");
	set_long(
@AVATAR
A thing like many other things.

AVATAR
	);
	set_weight(1);
	set_value(1);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
