#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("contest");
	set_id(({ "contest" }));
	set_short("contest");
	set_obvious_short("contest");
	set_long(
@AVATAR
contest

AVATAR
	);
	set_weight(0);
	set_value(1);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("constitution",-24);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("constitution",24);
	return 1;
}
