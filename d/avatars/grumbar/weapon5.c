#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Invisible Dagger");
	set_id(({ "dagger" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^Invisible Dagger%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible dagger%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(3);
	set_value(250000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",10);
	set_ac(-1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^WHITE%^Glass shards %^BLACK%^fly and then suddenly disappear as the weapon wielded by %^CYAN%^"+ETOQCN+" %^BLACK%^strikes %^CYAN%^"+targ->QCN+" %^BLACK%^squarely.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^RESET%^%^BOLD%^%^WHITE%^"%^BLACK%^Ah, puny person.  I think i'll take a little bit of that soul of yours now, seeings how i'm hungry%^WHITE%^"%^RESET%^");
	}
}