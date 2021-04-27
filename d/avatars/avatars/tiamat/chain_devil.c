#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("chain of the devil");
	set_id(({ "chain", "chains", "flail" }));
	set_short("%^BOLD%^%^BLACK%^C%^RESET%^ha%^BOLD%^%^BLACK%^i%^RESET%^n of the %^RED%^Devil%^RESET%^");
	set_obvious_short("%^RESET%^A %^BOLD%^%^BLACK%^dark %^RESET%^heavy %^BOLD%^%^BLACK%^c%^RESET%^ha%^BOLD%^%^BLACK%^i%^RESET%^n");
	set_long(
@AVATAR
%^RESET%^This thick, heavy chain is an unlikely weapon.  It has been forged from strong metal, and each link is about the size of a small hand.  Though there is little battle damage on the chain, it has a %^BOLD%^%^BLACK%^heavy charred%^RESET%^ appearance.  Though not a traditional weapon, it is obviously meant to be used as such: A large ring wrapped in leather is affixed to one end and used as a grip.  A few of the links have sharp barbs stained with %^RED%^blood%^RESET%^.  It seems to radiate it owns heat as you handle it.

AVATAR
	);
	set_weight(9);
	set_value(400);
	set_lore(
@AVATAR
Chains of the Devil are foul creations forged in lawful and evil planes.  The origin of the metal is unknown but it rarely fails and never deteriorates.  The weapons are thought to have some measure of their own intelligence and are favored by the Kyton, an order of devil also known as a Chain Devil.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,9);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RED%^As "+ETOQCN+" wields the chain, it arches like a serpent ready to strike!",ETO);
	tell_object(ETO,"%^RED%^As you wield the chain, it wraps around your forearm and arches, ready to strike!");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^RED%^As "+ETOQCN+" unwields the chain, it goes limp.",ETO);
	tell_object(ETO,"%^RED%^The chain goes limp as you unwield it.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^The chain wielded by "+ETOQCN+" springs to life and lashes out at "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The chain grows longer and lashes out at "+targ->QCN+" with its own evil intent!");
	tell_object(targ,"%^BOLD%^%^RED%^The chain wielded by "+ETOQCN+" springs to life and lashes out at you!");
		return roll_dice(1,6)+0;	}

}
