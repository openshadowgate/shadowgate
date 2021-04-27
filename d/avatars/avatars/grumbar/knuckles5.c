#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Invisible Knuckles");
	set_id(({ "knuckles" }));
	set_short("%^RESET%^%^BLACK%^Invisible Knuckles%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible knuckles%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(3);
	set_value(50000);
	set_type("bludgeoning");
	set_prof_type("knuckles");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",10);
	set_ac(-5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^The skeleton's silty hand disappears as the weapon is wielded.%^RESET%^",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^You see a glimmer, like the reflection of light in a mirror, but then it is gone.%^RESET%^",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^BLACK%^Parts of people being attacked disappear momentarily as the weapon glides and glimmers and %^WHITE%^STRIKES %^BLACK%^its opponent%^WHITE%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^You scream silently as the invisible weapon strikes you and causes where it hit to disappear momentarily.%^RESET%^");
	}
}