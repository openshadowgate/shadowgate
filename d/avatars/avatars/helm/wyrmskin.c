#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wyrmskin");
	set_id(({ "wyrmskin armor", "armor", "hide", "wyrmskin", "skin", "armor" }));
	set_short("%^RESET%^%^RED%^wyrmskin armor%^RESET%^");
	set_obvious_short("a suit of hide armor");
	set_long(
@AVATAR
%^RESET%^%^RED%^Crafted from the skin of the old wyrms this armor joins the best of two worlds. The enchanted inner hide, carefully tanned and joined together by a powerful armorsmith creates the perfect combination of light weight and protection. This particular suit of armor is a deep red colour and you can still see the texture of the scales.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(2688);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(4);
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
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-5);
	return 1;
}
