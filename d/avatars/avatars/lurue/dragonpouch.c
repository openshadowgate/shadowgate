#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("pouch");
	set_id(({ "pouch" }));
	set_short("%^RESET%^%^ORANGE%^a little leather pouch%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a little leather pouch%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This pouch is made of leather and appears to have been fashioned to hold a few small things.  A leather cord winds its way through several punched holes at the top allowing the pouch to be drawn open or closed as needed.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",-1);
	set_ac(15);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",30);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-30);
	return 1;
}
