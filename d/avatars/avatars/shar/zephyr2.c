#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("zephyr breeze");
	set_id(({ "rapier", "sword", "zephyr breeze" }));
	set_short("%^BOLD%^%^BLUE%^Z%^BLACK%^e%^WHITE%^p%^BLUE%^h%^BLACK%^y%^WHITE%^r%^BLUE%^'s %^BLACK%^Br%^WHITE%^ee%^BLACK%^ze%^RESET%^");
	set_obvious_short("A rapier");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^The hilt and crossguard of this rapier is crafted out of electrum with %^WHITE%^titanium%^BLUE%^ inlays.  The metal has been shaped to look like a wing that connects to the pommel, offering a fair ammount of protect the fencer's hand.  From the center of the hilt, an almost invisible like material rises forth and tapper off to a narrow point.  The material seems to be well formed, with no apparent seams or fissures in the blade.

AVATAR
	);
	set_weight(4);
	set_value(1500);
	set_lore(
@AVATAR
Zephyr's Breeze was crafted for Fethderal Thezelarnd, a swashbuckling half-elf of Akadi.  The Blue Feather, as he liked to be known, was a brazen and bold individual.  There are quite a few stories of how he performed raids against the church of Grumbar and stole precious artifacts.  Though, that did little to save him from the slavers of Tonovi and very cross Xvimit

AVATAR
	);
	set_type("piercing");
	set_prof_type("rapier");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s clothing and hair is ruffled by a breeze",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel a breeze ruffle your clothing as your wield the rapier.");
	ETO->add_attack_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^You feel the winds pass through",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the winds pass through");
	ETO->add_attack_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 230){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" moves with a switftness, striking "+targ->query_cap_name()+" twice!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The winds push you along, allowing for a second attack against "+targ->query_cap_name()+"");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" moves with a switftness, striking you twice!");
		return roll_dice(2,6)+2;	}
}