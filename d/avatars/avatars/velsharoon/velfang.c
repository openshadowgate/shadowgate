#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("fang");
	set_id(({ "fang", "velsharoons fang", "tooth", "canine tooth" }));
	set_short("%^RED%^Velsharoon's %^ORANGE%^Canine%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^large %^RESET%^%^ORANGE%^canine%^BOLD%^%^WHITE%^ tooth%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is one of %^RESET%^%^RED%^Velsharoon's%^BOLD%^%^WHITE%^ canine teeth. Instead of being smooth, it is %^RESET%^%^BLUE%^wickedly %^RED%^s%^ORANGE%^e%^RED%^r%^ORANGE%^r%^RED%^a%^ORANGE%^t%^RED%^e%^ORANGE%^d%^BOLD%^%^WHITE%^. The tooth extends far below his upper jaw and is stained a perpetual %^RED%^blood red%^WHITE%^. The tooth is %^RESET%^hollow%^BOLD%^ as if he could use it to drink through. Why would a skull wish to drink?%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set("strbonus",1);
	set_type("slashing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",5);
	set_ac(2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^You watch in horror as "+ETOQCN+" snaps his jaw shut and a "+query_short()+" extends from his upper jaw!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You snap your jaw together as a "+query_short()+" extends from your upper jaw.%^RESET%^");
	ETO->add_attack_bonus(3);
	ETO->add_damage_bonus(10);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" rolls his skull back and thankfully the "+query_short()+" slides up into his jawline.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You roll your head back as the "+query_short()+" slides back into your jawline.%^RESET%^");
	ETO->add_attack_bonus(-3);
	ETO->add_damage_bonus(-10);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^RED%^"+ETOQCN+" seems to relish tearing his "+query_short()+" into "+targ->QCN+" a little too much.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^You tear the "+query_short()+" into "+targ->QCN+" with gusto!%^RESET%^");
	tell_object(targ,"%^RED%^"+ETOQCN+"'s "+query_short()+" tears into you with excruciating agony!%^RESET%^");
		return roll_dice(1,20)+0;	}

}
