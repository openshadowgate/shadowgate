#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Spear of the hunt");
	set_id(({ "spear" }));
	set_short("%^BOLD%^%^GREEN%^A 6 foot spear, with %^BLUE%^F%^YELLOW%^e%^BLUE%^a%^YELLOW%^t%^BLUE%^h%^YELLOW%^e%^BLUE%^r%^YELLOW%^s %^GREEN%^attached at the blade%^RESET%^");
	set_obvious_short("A large Spear, nearing 6 feet in length");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This spear has obviously been crafted by a master weaponsmith, the design and the ornamentation of the long rigid shaft is expertly and painstakingly mastered into what can only be described as the perfect spear.


The bladed end of the spear, appears to have an almost %^CYAN%^iridescent blue glow to it, and it appears to have been forged from the finest of cobalt.%^GREEN%^ Intriguing runes have been crafted into the blade, and you can see it represents %^YELLOW%^a woman staking a large bear with the spear.%^GREEN%^ Around the joining of the blade and the wood, you can see beautiful %^BLUE%^F%^YELLOW%^e%^BLUE%^a%^YELLOW%^t%^BLUE%^h%^YELLOW%^e%^BLUE%^r%^YELLOW%^s%^GREEN%^.

AVATAR
	);
	set_weight(8);
	set_value(0);
	set_type("piercing");
	set_prof_type("spear");
	set_size(3);
	set_wc(2,7);
	set_large_wc(2,7);
	set_property("enchantment",4);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" wields the large spear, and looks ready for battle%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You wield the large spear, and get ready for battle%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" looks relaxed as the spear is unwielded%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You unwield the large spear, and relax your muscles%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" hits "+targ->QCN+" with great %^RED%^FORCE! and the blood spills..%^GREEN%^%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^You hit with great %^RED%^FORCE! and the blood spills from %^GREEN%^"+targ->QCN+"%^RESET%^");
	tell_object(targ,"");
		return roll_dice(3,4)+-1;	}
}