#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Ivory Bracers");
	set_id(({ "bracers", "bracer", "ivory bracer", "ivory bracers", "Bracers", "Bracer", "Ivory Bracer", "Ivory Bracers" }));
	set_short("%^BOLD%^%^WHITE%^I%^WHITE%^v%^BOLD%^%^WHITE%^o%^WHITE%^r%^BOLD%^%^WHITE%^y %^YELLOW%^Bracers%^RESET%^");
	set_obvious_short("Ivory Bracers");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^These bracers are made from a dull smooth piece of Ivory.  Etched into the upper side of them are several trees, which have been altered to a %^RESET%^%^GREEN%^forest green%^BOLD%^%^WHITE%^ hue, contrasting with the otherwise dull white.  Beautifully carved into the center of the etched forest, is a %^YELLOW%^unicorn%^RESET%^%^BOLD%^%^WHITE%^, it's sleek and powerful body a brilliant %^RESET%^%^WHITE%^white%^BOLD%^%^WHITE%^.  It's head is looking forward, as if it's staring directly at you

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+"'s fingers trace the outline of the unicorn on the "+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You allow your fingers to trace the outline of the unicorn.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" sighs softly!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^With a soft sigh you remove the "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
