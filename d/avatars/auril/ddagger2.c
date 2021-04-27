#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("death dagger");
	set_id(({ "death dagger", "dagger" }));
	set_short("%^BOLD%^%^BLACK%^Leklestor's re%^BOLD%^%^WHITE%^ve%^BOLD%^%^BLACK%^nge%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A light gr%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^y dagger %^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This exquisite dagger seems to be made from a %^BOLD%^%^WHITE%^pale %^BOLD%^%^BLACK%^dark metal. The blade is slightly transparent, warping the world through it's milky inners. The pommel has a small %^BOLD%^%^RED%^red ruby %^BOLD%^%^BLACK%^at the end of it with a swirling %^BOLD%^%^WHITE%^mi%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^t %^BOLD%^%^BLACK%^inside. 

AVATAR
	);
	set_weight(3);
	set_value(10000);
	set_lore(
@AVATAR
The dagger of Leklestor has a very short but dreadful history...

One hundred fifty years ago there was an old mage by the name of Helstrop who lived in the city of Seneca, amongst the guild there. Corrupted by the evils of Intruder and his minions, Helstrop plotted his own plans within the city, using an assassin by the name of Leklestor the violent. 

Leklestor was given this dagger for the murder of a powerful Senecan official by Helstrop. Helstrop gave him the dagger on the obligation that he would get the weapon back after the mission was completed. It would not turn out to be so. After the dirty deed was done, Leklestor told Helstrop he had completed the mission. When Helstrop asked for the dagger, to his surprise, Leklestor stabbed him into the throat. Soon after, Leklestor disappeared, no one knowing what happened to the dagger...after the slaying of the powerful mage in but a stroke. 

Rumors say those that are killed by the dagger linger still, waiting for revenge...

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,6);
	set_property("enchantment",4);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" wield the dagger and tendrils wrap themselves around "+ETOQCN+"'s wrist.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You wield the weapon and hear the begging of many from within the blade.%^RESET%^");
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" unwields the dagger and the tendrils recoil back into the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The begging still lingers momentarily as you unwield the blade.");
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 5){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+targ->QCN+"'s eyes go pale for a moment.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You see part of the soul of the individual leave "+targ->QCN+"'s eyes and enter the %^BOLD%^%^RED%^ruby%^BOLD%^%^WHITE%^.");
	tell_object(targ,"%^BOLD%^%^WHITE%^You feel strange as something tugs at your soul.");
		return roll_dice(4,10)+10;	}
}