#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("stormcloak");
	set_id(({ "cloak" }));
	set_short("%^BOLD%^%^RED%^Cloak of the %^BOLD%^%^RED%^S%^BOLD%^%^BLACK%^t%^BOLD%^%^RED%^o%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^m%^RESET%^");
	set_obvious_short("A cloak");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This long billowing cloak is made of a sheer substance of sort. The material is colored in such a way that it looks like clounds and smoke that are magically %^BOLD%^%^YELLOW%^enchanted %^BOLD%^%^RED%^to move about as if a rumbling storm. Energy crackles within, and its image is breathtaking.

AVATAR
	);
	set_weight(3);
	set_value(10000);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The sound of storms can be heard for a brief moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Storms can be heard as you wear the cloak.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The storm fades.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The sounds fade as you remove the cloak.");
	ETO->set_property("magic resistance",-5);
	return 1;
}
