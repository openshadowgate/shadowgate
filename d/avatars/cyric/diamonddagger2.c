#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "diamond dagger", " dagger" }));
	set_short("%^BLUE%^%^BOLD%^D%^RESET%^%^BOLD%^i%^BLUE%^a%^RESET%^%^BOLD%^m%^BLUE%^o%^RESET%^%^BOLD%^n%^BLUE%^d %^RESET%^%^BOLD%^D%^RESET%^%^BOLD%^a%^BLUE%^g%^RESET%^%^BOLD%^g%^BLUE%^e%^RESET%^%^BOLD%^r%^RESET%^");
	set_obvious_short("crystal dagger");
	set_long(
@AVATAR
On closer inspection, the crystal dagger is actually a dagger made entirely from what appears to be a huge blue-white diamond!   Light reflects through the blade and hilt alike, but the blade glows with a faint inner amber glow.  Such a weapon definitely rare, if not unique, the size of the diamond itself would fetch a fortune.  You worry about anyone knowing it is in your posession.

AVATAR
	);
	set("read",
@AVATAR
You can't read that.

AVATAR
	);
	set_weight(3);
	set_value(15000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BOLD%^You grasp the diamond firmly%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BOLD%^You release the magnificent "+query_short()+"%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^BOLD%^"+ETO->query_cap_name()+" inflicts a vicious blow upon "+targ->query_cap_name()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^"+ETO->query_cap_name()+" slices you severely with the "+query_short()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^The "+query_short()+" slices effortlessly through "+targ->query_cap_name()+"!%^RESET%^");
		return roll_dice(4,3)+6;	}
}
