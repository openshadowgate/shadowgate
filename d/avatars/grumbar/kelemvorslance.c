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
%^RESET%^This lance is awesome in its appearance.  It is made from onyx and jade but that is not what is so unusual.  The jade and onyx has been twisted, looking like one piece of material now, turning over and over again.  The lance has been tipped with a bronze cap, it's hilt wound and strengthened with the tendon of a dead dragon.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(25000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(medium);
	set_wc(5,20);
	set_large_wc(6,20);
	set_property("enchantment",5);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to relax slightly and then look saddened as he wields "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the blessing of your lord as you wield "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks visibly better after unwielding "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You thank your lord for the gift and look forward to wielding it again%^RESET%^");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+targ->QCN+" shrieks horribly as "+ETOQCN+" 's "+query_short()+" strikes it stoutly%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^"+targ->QCN+" shrieks horribly as "+query_short()+" strikes it stoutly%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^AHHH!  I take your life now!!%^RESET%^");
	}
}