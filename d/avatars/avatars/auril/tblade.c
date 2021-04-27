#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tyr blade");
	set_id(({ "sword" }));
	set_short("%^BOLD%^%^RED%^A %^RESET%^massive %^BOLD%^%^GREEN%^emerald %^RESET%^two-handed %^BOLD%^%^BLACK%^sword%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A %^RESET%^massive %^BOLD%^%^GREEN%^emerald %^RESET%^two-handed %^BOLD%^%^BLACK%^sword%^RESET%^");
	set_long(
@AVATAR
This finely crafted two-handed sword has a handle made completely from a piece of %^BOLD%^%^GREEN%^emerald%^RESET%^. The long stainless steel blade has been %^BOLD%^%^WHITE%^silvered %^RESET%^and is keenly sharp. The crafting of this blade was well though out. The pommel of the blade is a %^RESET%^%^GREEN%^jade %^BOLD%^%^CYAN%^sphere%^RESET%^.

AVATAR
	);
	set_weight(16);
	set_value(500);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(1,10);
	set_large_wc(3,6);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You wrap your hand around the handle and grip it tightly.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You release the handle of the sword.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" cuts "+targ->QCN+" deeply with your sword!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You cut "+targ->QCN+" deeply with your sword!");
	tell_object(targ,"%^BOLD%^%^RED%^You are cut deeply by the sword!");
		return roll_dice(1,4)+0;	}
}