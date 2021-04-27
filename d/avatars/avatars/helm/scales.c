#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("scales");
	set_id(({ "scales" }));
	set_short("%^RESET%^%^RED%^scales%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^scales%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(400);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",1);
	set_ac(20);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->set_property("magic resistance",5);
	return 1;
}
