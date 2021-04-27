#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("darumsword2");
	set_id(({ "sword", "longsword", "long sword" }));
	set_short("A %^RESET%^%^BOLD%^%^WHITE%^S%^BOLD%^%^YELLOW%^p%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^WHITE%^k%^BOLD%^%^YELLOW%^l%^RESET%^%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g %^BOLD%^%^BLUE%^longsword with a sharp edge.%^RESET%^");
	set_obvious_short("A %^RESET%^%^BOLD%^%^WHITE%^S%^BOLD%^%^YELLOW%^p%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^WHITE%^k%^BOLD%^%^YELLOW%^l%^RESET%^%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g %^BOLD%^%^BLUE%^longsword with a sharp edge.%^RESET%^");
	set_long(
@AVATAR
A %^RESET%^%^BOLD%^%^WHITE%^S%^BOLD%^%^YELLOW%^p%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^WHITE%^k%^BOLD%^%^YELLOW%^l%^RESET%^%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g %^BOLD%^%^BLUE%^longsword with a sharp edge. The blade been carved with a pattern of %^BOLD%^%^BLUE%^s%^WHITE%^o%^BOLD%^%^BLUE%^n%^WHITE%^g%^BOLD%^%^BLUE%^b%^WHITE%^i%^BOLD%^%^BLUE%^r%^WHITE%^d %^BOLD%^%^BLUE%^sitting on a %^RESET%^%^ORANGE%^branch. %^BOLD%^%^BLUE%^The crosspiece of the sword resembles two %^BOLD%^%^BLUE%^s%^WHITE%^o%^BOLD%^%^BLUE%^n%^WHITE%^g%^BOLD%^%^BLUE%^b%^WHITE%^i%^BOLD%^%^BLUE%^r%^WHITE%^d%^BOLD%^%^BLUE%^ facing away from each other one with eyes made of %^BOLD%^%^WHITE%^sapphiere %^BOLD%^%^BLUE%^the other with eyes of %^MAGENTA%^amethyst. %^BOLD%^%^BLUE%^The hilt has been wraped with fine %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLUE%^ to provide a good grip. %^BOLD%^%^BLUE%^The Pommel of the sword is a bell, what makes the sword jingle at every swing and hit. 

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,8);
	set_large_wc(2,8);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" wields the weapon the bell on the %^YELLOW%^pommel %^WHITE%^jingles%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As you wield the weapon the bell on the %^YELLOW%^pommel %^WHITE%^jingles%^RESET%^");
	ETO->do_damage("torso",random(0));
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" unwields the weapon the bell on the %^YELLOW%^pommel %^WHITE%^jingles%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As you unwield the weapon the bell on the %^YELLOW%^pommel %^WHITE%^jingles%^RESET%^");
	ETO->do_damage("torso",random(0));
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^The bell on the %^YELLOW%^pommel %^WHITE%^jingles as "+ETOQCN+" hits "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The bell on the %^YELLOW%^pommel %^WHITE%^jingles as you hit "+targ->QCN+"%^RESET%^");
	tell_object(targ,"");
	}
}