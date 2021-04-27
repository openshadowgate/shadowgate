#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("flyswatter");
	set_id(({ }));
	set_short("%^RESET%^%^CYAN%^a flyswatter the size of a small horse%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a flyswatter the size of a small horse%^RESET%^");
	set_long(
@AVATAR
This is a very large flyswatter. Rather effective against unruly players.

AVATAR
	);
	set_weight(4);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("flyswatter");
	set_size(3);
	set_wc(1000,1000);
	set_large_wc(1000,1000);
	set_property("enchantment",8);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^CYAN%^The flies buzzing around your head fall silent in dread anticipation...%^RESET%^");
	ETO->add_attack_bonus(10000);
	ETO->add_damage_bonus(100000);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^CYAN%^Damnit, the flies are back.%^RESET%^");
	ETO->add_attack_bonus(-10000);
	ETO->add_damage_bonus(-100000);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+"^RESET%^%^CYAN%^ swats "+targ->query_cap_name()+" hard over the head.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^CYAN%^You swat "+targ->query_cap_name()+"%^RESET%^%^CYAN%^ hard over the head.%^RESET%^");
	tell_object(targ,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+"^RESET%^%^CYAN%^ swats you hard over the head.%^RESET%^");
		targ->set_paralyzed(roll_dice(10,0)+0);
return 0;	}
}