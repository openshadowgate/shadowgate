#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("heart");
	set_id(({ "heart" }));
	set_short("%^BOLD%^%^RED%^A red beating heart%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A red beating heart%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A red beating heart%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
This was once the heart of a great follower of Akadi, Sherlock. 

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(4);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^When you wear the heart you feel your power grow.");
	ETO->set_property("magic resistance",125);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-125);
	return 1;
}
