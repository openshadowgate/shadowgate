#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Cloak of Darkness");
	set_id(({ "cloak" }));
	set_short("%^BLACK%^Cloak of Darkness");
	set_obvious_short("%^BLACK%^Cloak of Darkness");
	set_long(
@AVATAR
%^BLACK%^This is Xvim's Cloak of Darkness

AVATAR
	);
	set_weight(50);
	set_value(0);
	set_max_internal_encumbrance(500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",15);
	set_ac(150);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"%^BLACK%^Xvim wears his cloak of Darkness and the world turns pitchdark",TP);
	tell_object(TP,"");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BLACK%^Xvim removes his cloak of Darkness and the sun shines once again",TP);
	tell_object(TP,"");
	TP->set_property("magic resistance",5);
	return 1;
}
