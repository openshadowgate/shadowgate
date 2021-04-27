#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("garrotte wire");
	set_id(({ "wire", "garrotte", "garrotte wire" }));
	set_short("%^BOLD%^%^WHITE%^A strangle %^RESET%^%^ORANGE%^cord%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A strangle %^RESET%^%^ORANGE%^cord%^RESET%^");
	set_long(
@AVATAR
This is a long thin wire with small %^RESET%^%^ORANGE%^wooden %^RESET%^handles on each end. This weapon is commonly used to hold and incapacitate the victims though usually it takes some time and strength to get the job done.

AVATAR
	);
	set_weight(1);
	set_value(50);
	set_type("slashing");
	set_prof_type("garrotte");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You grab a hold of the wooden handles and prepare to attack your victim.");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" firmly holds onto "+targ->QCN+" attempting to strangle him!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You strangle your opponent, holding him in place!");
	tell_object(targ,"%^BOLD%^%^RED%^You feel the wire wrapped around your neck, holding you still and sufficating!");
		targ->set_paralyzed(roll_dice(1,4)+-3);
return 0;	}
}