#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("invis dagger");
	set_id(({ "dagger" }));
	set_short("%^RESET%^%^BLACK%^Invisible Dagger%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible dagger%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(3);
	set_value(250000);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(3,4);
	set_large_wc(3,4);
	set_property("enchantment",10);
	set_ac(-5);
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
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^WHITE%^YES!  %^BLACK%^I take the heathens life!%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^WHITE%^YES!  %^BLACK%^I take your life, heathen!%^RESET%^");
		return roll_dice(2,4)+0;	}
}