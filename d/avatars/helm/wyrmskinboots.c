#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wyrmskinboots");
	set_id(({ "boots", "wyrmskin boots", "skin boots" }));
	set_short("%^RESET%^%^RED%^wyrmskin boots%^RESET%^");
	set_obvious_short("a pair of hide boots");
	set_long(
@AVATAR
%^RESET%^%^RED%^Crafted from the skin of the old wyrms this armor joins the best of two 
worlds. The enchanted inner hide, carefully tanned and joined together by a powerful 
armorsmith creates the perfect combination of light weight and protection. These particular 

boots are a deep red colour and you can still see the texture of the scales.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1513);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-3);
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
