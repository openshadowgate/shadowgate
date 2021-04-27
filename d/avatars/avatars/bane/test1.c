#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("testring");
	set_id(({ "ring" }));
	set_short("ring");
	set_obvious_short("ring");
	set_long(
@AVATAR
ring

AVATAR
	);
	set_weight(0);
	set_value(1);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",-1);
	return 1;
}
