#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^dra%^BOLD%^g%^RESET%^%^RED%^on's %^BOLD%^b%^RESET%^%^RED%^rea%^BOLD%^t%^RESET%^%^RED%^h sword%^RESET%^");
	set_id(({ "sword", " two handed sword", " flambard", " dragon's breath" }));
	set_short("%^RESET%^%^RED%^dra%^BOLD%^g%^RESET%^%^RED%^on's %^BOLD%^b%^RESET%^%^RED%^rea%^BOLD%^t%^RESET%^%^RED%^h sword%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^steel flambard sword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^this blade, quite possibly the largest two handed sword you have ever seen, measures almost six feet in length from pommel to tip. The blade of the sword has a %^BOLD%^waving undulating edge%^RESET%^, like a %^RED%^flame%^RESET%^. Three quarters of the way towards the grip are two spikes that extend out for parrying, and a %^BLACK%^%^BOLD%^blood groove%^RESET%^ runs the entire length of the blade. The crossguard is formed from %^RESET%^%^GREEN%^ja%^BOLD%^d%^RESET%^%^GREEN%^e%^RESET%^ into the shape of a %^GREEN%^dragon's open jaw%^RESET%^, with two sparkling %^RESET%^%^RED%^%^BOLD%^r%^RESET%^%^RED%^u%^RESET%^bi%^RED%^e%^BOLD%^s%^RESET%^ set as eyes. The hilt is wrapped with a %^ORANGE%^fine leather%^RESET%^, and the pommel is a %^BLACK%^%^BOLD%^cat's eye gem%^RESET%^. 

AVATAR
	);
	set_weight(15);
	set_value(15000);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ grips the "+query_short()+"%^BLACK%^%^BOLD%^, holding it with a small smile%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You grip the hilt of the "+query_short()+"%^BLACK%^%^BOLD%^ with both hands, smiling at the sudden %^RESET%^%^RED%^rush%^BLACK%^%^BOLD%^ of power%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ releases the "+query_short()+"%^BLACK%^%^BOLD%^, a frown playing across their features%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You release the hilt of the "+query_short()+"%^BLACK%^%^BOLD%^ with a feeling of loss%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^As "+ETOQCN+"%^RESET%^%^RED%^ cuts deep into "+targ->QCN+"%^RESET%^%^RED%^, the blade bursts into %^BOLD%^flame%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^RED%^As your "+query_short()+"%^RESET%^%^RED%^ strikes deep into "+targ->QCN+"%^RESET%^%^RED%^, the entire blade bursts into %^BOLD%^flames%^RESET%^");
	tell_object(targ,"%^RESET%^%^RED%^As "+ETOQCN+"%^RESET%^%^RED%^'s "+query_short()+"%^RESET%^%^RED%^ cuts into your flesh, you feel a sudden burst of %^BOLD%^flame%^RESET%^%^RED%^ rush over you%^RESET%^");
		return roll_dice(3,6)+-1;	}
}