#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("rose petal");
	set_id(({ "petal", "rose petal", "petal" }));
	set_short("%^BOLD%^%^RED%^a r%^MAGENTA%^o%^RESET%^%^MAGENTA%^s%^BOLD%^%^RED%^e p%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^al%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^a r%^MAGENTA%^o%^RESET%^%^MAGENTA%^s%^BOLD%^%^RED%^e p%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^al%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This little r%^MAGENTA%^o%^RESET%^%^MAGENTA%^s%^BOLD%^%^RED%^e p%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^al could be from any rose anywhere, and yet it seems to remain bright and vibrant despite being plucked from its flower.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-10);
	return 1;
}
