#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("pocket");
	set_id(({ "pocket" }));
	set_short("pocket");
	set_obvious_short("pocket");
	set_long(
@AVATAR
pocket 

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"blach",TP);
	tell_object(TP,"blach");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"blach",TP);
	tell_object(TP,"blach");
	TP->set_property("magic resistance",5);
	return 1;
}
