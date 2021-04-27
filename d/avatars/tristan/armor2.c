#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor");
	set_id(({ "armor" }));
	set_short("armor");
	set_obvious_short("armor");
	set_long(
@AVATAR
armor

AVATAR
	);
	set_weight(2);
	set_value();
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"blah",TP);
	tell_object(TP,"blah");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"blah",TP);
	tell_object(TP,"blah");
	TP->set_property("magic resistance",5);
	return 1;
}
