#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Invisible Nails");
	set_id(({ "nails", "blades" }));
	set_short("%^RESET%^%^BLACK%^Invisible Nails%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible nails%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(7);
	set_value(750000);
	set_type("piercing");
	set_prof_type("knuckles");
	set_size(medium);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(5);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-5);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"");
		targ->set_paralyzed(roll_dice(2,4)+-1);
return 0;	}
}