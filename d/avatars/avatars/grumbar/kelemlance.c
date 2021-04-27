#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("lance");
	set_id(({ "lance" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^Unde%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^d's Dem%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^se%^RESET%^");
	set_obvious_short("an %^BOLD%^%^BLACK%^onyx %^RESET%^and %^GREEN%^jade %^RESET%^lance");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This lance is awesome in its appearance.  It is made from onyx and jade but that is not what is so unusual.  The jade and onyx has been twisted, looking like one piece of material now, turning over and over again.  The lance has been tipped with a bronze cap, it's hilt wound and strengthened with the tendon of a dead dragon.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(10000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(medium);
	set_wc(5,6);
	set_large_wc(6,6);
	set_property("enchantment",5);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" seems visibly saddened after wielding "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Ahhhh... Don't worry, Knight, I am with you%^RESET%^");
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks happiers as he unwields "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^When you wield me again, I'll be here to guide you%^RESET%^");
	ETO->add_damage_bonus(-2);
	return 1;
}
