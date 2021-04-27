#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Demon Snare");
	set_id(({ "whip", "demon snare" }));
	set_short("%^BLACK%^%^BOLD%^De%^RESET%^%^RED%^m%^BLACK%^%^BOLD%^o%^RESET%^n %^BLACK%^%^BOLD%^S%^RESET%^%^RED%^n%^BLACK%^%^BOLD%^a%^RESET%^r%^BLACK%^%^BOLD%^e%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black whip formed from shadow%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^crafted from shadow itself, this whip is huge, its snaking barbed length nearing ten feet. The handle of the whip is two feet in length and bound in the %^RESET%^%^ORANGE%^skin%^BLACK%^%^BOLD%^ of some unknown beast. As the whip moves, a sound like the %^RESET%^%^CYAN%^low whimper%^BLACK%^%^BOLD%^ of an animal can be heard.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(10000);
	set_lore(
@AVATAR
The Demon snare was crafted by a powerfull mage looking for a way to bind creatures he called to his will. He took the very substance of the shadow planes and bound it into a woven form. The whip is said to be able to bind even the most powerfull of outsider in its grasp

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^As "+ETOQCN+" wields the "+query_short()+" shadows whip angrily around them%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you wield the "+query_short()+" shadows whip angrily around you%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^As "+ETOQCN+" lets go of the "+query_short()+", the shadows calm around them%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you let go of the "+query_short()+", the shadows calm around you%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BLACK%^%^BOLD%^The barbs of shadows wrap around "+targ->QCN+", pulling them towards "+ETOQCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^The barbs of shadows wrap around "+targ->QCN+", pulling them towards you%^RESET%^");
	tell_object(targ,"%^BLACK%^%^BOLD%^You are rocked forward as "+ETOQCN+"'s "+query_short()+" pulls you towards them%^RESET%^");
		return roll_dice(3,4)+-1;	}
}