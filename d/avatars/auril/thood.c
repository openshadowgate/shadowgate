#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hood");
	set_id(({ "hood" }));
	set_short("%^BOLD%^%^BLACK%^Thieve's hood%^RESET%^");
	set_obvious_short("A hood");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This hood covers the wearers head comfortably, masking it from view in an unnaturally array of shadows. 

AVATAR
	);
	set_weight(2);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" slips on the black hood, concealing his face from view.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip on the black hood.");
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" slips off the black hood,  his face comes into view.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip off the black hood.");
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
