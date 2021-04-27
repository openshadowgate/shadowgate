#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("a black gauntlet");
	set_id(({ "hand of bane", "gauntlet", "spiked gauntlet" }));
	set_short("%^BOLD%^%^BLACK%^Hand of %^BOLD%^%^GREEN%^Bane%^RESET%^");
	set_obvious_short("A black gauntlet");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^ A single gauntlet made out of a black oily metal.  The gauntlet is rather thick in design, with many plates that overlap giving solid protection to one's hand.  Fused into the metal spikes in all shapes and sizes rise up across the back of the gauntlet.  Some spikes are as big as two inches!  The spikes spiral around the lower sections of the gauntlet, further adding to the sinister feeling of this piece of armor.  %^BOLD%^^%GREEN%^Emeralds%^BLACK%^ have been set into the gauntlet, all uniform in shape and size.

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_lore(
@AVATAR
The Hand of Bane is the favored weapons by followers of Bane, from tyrannt warriors to zealot priests and bloodthirsty knights.  The followers of Bane are trained to use the gauntlets with savage cruelity that would put a Lovite to shame, briefly.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The time for Bane's will to be done has come.");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your work is not done until every living creature has bowed before the Tyrannt, Bane!");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" inbeds their spiked gauntlet into "+targ->query_cap_name()+". With a sickening squish sound "+ETO->query_cap_name()+" pulls their arm free, leaving "+targ->query_cap_name()+" full of holes",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You imbed the spikes of the gauntlet into "+targ->query_cap_name()+".  With a sickening squish sound you pull your arm free, leaving them full of holes.");
	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+" imbeds their spiked gauntlet into you!  With a sickening squish sound "+ETO->query_cap_name()+" pull their arm free, leaving you full of holes!");
		return roll_dice(3,4)+-1;	}
}