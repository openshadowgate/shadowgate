#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("glove");
	set_id(({ "gloves" }));
	set_short("%^BOLD%^%^BLACK%^Gloves of the Shadow %^RESET%^");
	set_obvious_short("a pair of strange black gloves");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This pair of gloves is surrounded by an inky shadowy substance. The substance, which is the make up of shadows themselves, surrounds the glove and dance along it constantly. Wrapping themselves around the wearers forearm, they seem very comfortable.

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Shadows crawl up "+ETO->query_cap_name()+"'s forearm, wrapping themselves around it.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows crawl up your forearm, wrapping themselves around it.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The shadows disperse as "+ETO->query_cap_name()+" removes the gloves.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows disperse as you remove the gloves.");
	ETO->set_property("magic resistance",-5);
	return 1;
}
